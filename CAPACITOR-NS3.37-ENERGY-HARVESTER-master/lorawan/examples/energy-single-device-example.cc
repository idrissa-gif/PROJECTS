
/*
 * This script simulates a simple network to test capacitor source
 * and lora radio energy model.
 */

#include "ns3/basic-energy-harvester.h"
#include "ns3/boolean.h"
#include "ns3/callback.h"
#include "ns3/double.h"
#include "ns3/end-device-lora-phy.h"
#include "ns3/end-device-lorawan-mac.h"
#include "ns3/energy-harvester-container.h"
#include "ns3/gateway-lora-phy.h"
#include "ns3/class-a-end-device-lorawan-mac.h"
#include "ns3/gateway-lorawan-mac.h"
#include "ns3/integer.h"
#include "ns3/lora-net-device.h"
#include "ns3/lora-radio-energy-model.h"
#include "ns3/nstime.h"
#include "ns3/object.h"
#include "ns3/one-shot-sender-helper.h"
#include "ns3/packet.h"
#include "ns3/random-variable-stream.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/lora-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/node-container.h"
#include "ns3/position-allocator.h"
#include "ns3/periodic-sender-helper.h"
#include "ns3/energy-aware-sender-helper.h"
#include "ns3/command-line.h"
#include "ns3/basic-energy-source-helper.h"
#include "ns3/basic-energy-harvester-helper.h"
#include "ns3/lora-radio-energy-model-helper.h"
#include "ns3/network-server-helper.h"
#include "ns3/forwarder-helper.h"
#include "ns3/lora-packet-tracker.h"
#include "ns3/file-helper.h"
#include "ns3/names.h"
#include "ns3/config.h"
#include "ns3/string.h"
#include "ns3/config.h"
#include "ns3/variable-energy-harvester-helper.h"
#include "ns3/capacitor-energy-source.h"
#include "ns3/capacitor-energy-source-helper.h"
#include "ns3/lora-tx-current-model.h"
#include <algorithm>
#include <stdint.h>
#include <ctime>
#include <iostream>
#include <string>
#include <sys/types.h>

using namespace ns3;
using namespace lorawan;

NS_LOG_COMPONENT_DEFINE ("EnergySingleDeviceExample");

// Inputs
double simTime = 30;
double appPeriod = 4;
double capacitance = 6; // mF
int packetSize = 50;
double eh = 0.001;
uint8_t dr = 5;
bool confirmed = false;
std::string sender = "periodicSender";
std::string filenameRemainingVoltage = "remainingVoltage.txt";
std::string filenameEnergyConsumption = "energyConsumption.txt";
std::string filenameRemainingEnergy = "remainingEnergy.txt";
std::string filenameState = "deviceStates.txt";
std::string filenameEnoughEnergy = "energyEnoughForTx.txt";
std::string pathToInputFile = "/home/marty/work/ua/panels_data";
std::string filenameHarvesterSun = "/outputixys.csv";
std::string filenameHarvesterCloudy = "/outputixys_cloudy.csv";
bool remainingVoltageCallbackFirstCall = true;
bool energyConsumptionCallbackFirstCall = true;
bool enoughEnergyCallbackFirstCall = true;
bool stateChangeCallbackFirstCall = true;
int generatedPacketsAPP = 0;

// Callbcks

void
OnRemainingEnergyChange (double oldRemainingEnergy, double remainingEnergy)
{
  // NS_LOG_DEBUG (Simulator::Now().GetSeconds() << " " << remainingEnergy);
  // std::cout << Simulator::Now().GetSeconds() << " " << remainingEnergy << std::endl;
  // return std::to_string(Simulator::Now().GetSeconds()) + " " + std::to_string(remainingEnergy)
}

void
OnDeviceEnergyConsumption (double oldvalue, double energyConsumption)
{
  const char *c = filenameEnergyConsumption.c_str ();
  std::ofstream outputFile;
  if (energyConsumptionCallbackFirstCall)
    {
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      // Set the initial sleep state
      // outputFile << 0 << " " << 0 << std::endl;
      // NS_LOG_DEBUG ("Append initial state inside the callback");
      outputFile <<  "0 0" << std::endl;
      energyConsumptionCallbackFirstCall = false;
    }
  else
    {
    // Only append to the file
    outputFile.open (c, std::ofstream::out | std::ofstream::app);
    }

  outputFile << Simulator::Now ().GetSeconds () << " " << energyConsumption << std::endl;

  outputFile.close ();
}

void
OnRemainingVoltageChange (double oldRemainingVoltage, double remainingVoltage)
{

  NS_LOG_DEBUG("Callback");
  const char *c = filenameRemainingVoltage.c_str ();
  std::ofstream outputFile;
  if (remainingVoltageCallbackFirstCall)
    {
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      remainingVoltageCallbackFirstCall = false;
    }
  else
    {
      // Only append to the file
      outputFile.open (c, std::ofstream::out | std::ofstream::app);
    }

  outputFile << Simulator::Now ().GetMilliSeconds () << " " << remainingVoltage << std::endl;

  outputFile.close ();
}

void OnEnergyHarvested (double oldvalue, double totalEnergyHarvested)
{
  NS_LOG_DEBUG("Total energy harvested: " << totalEnergyHarvested);
  NS_LOG_DEBUG ("Energy harvested in this interval: " << totalEnergyHarvested - oldvalue);
}

void
EnergyDepletionCallback (void)
{
  NS_LOG_DEBUG("Energy depleted callback in main");
}

void
CheckEnoughEnergyCallback (uint32_t nodeId, Ptr<const Packet> packet,
                           Time time, bool boolValue)
{
  // std::cout << time.GetSeconds () << " "
  //           << "EnoughEnergy " << std::to_string (boolValue) << std::endl;

  const char *c = filenameEnoughEnergy.c_str ();
  std::ofstream outputFile;
  if (enoughEnergyCallbackFirstCall)
    {
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      enoughEnergyCallbackFirstCall = false;
    }
  else
    {
      // Only append to the file
      outputFile.open (c, std::ofstream::out | std::ofstream::app);
    }

  outputFile << Simulator::Now ().GetSeconds () << " " << boolValue << std::endl;

  outputFile.close ();

}


void
OnEndDeviceStateChange (EndDeviceLoraPhy::State oldstatus,
                        EndDeviceLoraPhy::State status)
{
  const char *c = filenameState.c_str ();
  std::ofstream outputFile;
  if (stateChangeCallbackFirstCall)
    {
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      // Set the initial sleep state
      outputFile << 0 << " " << 0 << std::endl;
      NS_LOG_DEBUG ("Append initial state inside the callback");
      stateChangeCallbackFirstCall = false;
    }
  else
    {
      // Only append to the file
      outputFile.open (c, std::ofstream::out | std::ofstream::app);
    }

  NS_LOG_DEBUG ("Added current state");
  outputFile << Simulator::Now ().GetSeconds () << " " << status << std::endl;

  outputFile.close ();
}

void
OnGeneratedPacket (void)    
{
  // NS_LOG_DEBUG("Generated packet at APP level");
  generatedPacketsAPP = generatedPacketsAPP + 1;
  NS_LOG_DEBUG("Generated APP packet = " << generatedPacketsAPP);
}

/***********
 ** MAIN  **
 **********/
int main (int argc, char *argv[])
{

  // Inputs
  CommandLine cmd;
  cmd.AddValue ("pathToInputFile",
                "Absolute path till the input file for the varaible energy harvester",
                pathToInputFile);
  cmd.AddValue ("capacitance", "capacitance[mF]",capacitance);
  cmd.AddValue ("simTime", "Simulation time [s]", simTime);
  cmd.AddValue ("appPeriod", "App period [s]", appPeriod);
  cmd.AddValue ("confirmed", "Send confirmed message", confirmed);
  cmd.AddValue ("dr", "dr", dr);
  cmd.AddValue ("packetSize", "PacketSize", packetSize);
  // cmd.AddValue ("enableVariableHarvester", "Enable harvester from input file",
  //                enableVariableHarvester);
  // cmd.AddValue ("sun", "Input from sunny day", sun);
  cmd.AddValue ("eh", "eh", eh);
  cmd.AddValue ("sender", "Application sender [energyAwareSender, periodicSender, multipleShots]", sender);
  cmd.Parse (argc, argv);

  // Set up logging
  LogComponentEnable ("EnergySingleDeviceExample", LOG_LEVEL_ALL);
  // LogComponentEnable ("LoraPacketTracker", LOG_LEVEL_ALL);
  // LogComponentEnable ("CapacitorEnergySource", LOG_LEVEL_ALL);
  // LogComponentEnable ("CapacitorEnergySourceHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("LoraRadioEnergyModel", LOG_LEVEL_ALL);
  // LogComponentEnable ("EnergyAwareSender", LOG_LEVEL_ALL);
  // LogComponentEnable ("EnergyHarvester", LOG_LEVEL_ALL);
  // LogComponentEnable ("VariableEnergyHarvester", LOG_LEVEL_ALL);
  // LogComponentEnable ("EnergySource", LOG_LEVEL_ALL);
  // LogComponentEnable ("BasicEnergySource", LOG_LEVEL_ALL);
  LogComponentEnable ("LoraChannel", LOG_LEVEL_ALL);
  LogComponentEnable ("LoraPhy", LOG_LEVEL_ALL);
  LogComponentEnable ("EndDeviceLoraPhy", LOG_LEVEL_ALL);
  LogComponentEnable ("SimpleEndDeviceLoraPhy", LOG_LEVEL_ALL);
  LogComponentEnable ("GatewayLoraPhy", LOG_LEVEL_ALL);
  LogComponentEnable ("SimpleGatewayLoraPhy", LOG_LEVEL_ALL);
  LogComponentEnable ("LoraInterferenceHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("LorawanMac", LOG_LEVEL_ALL);
  // LogComponentEnable ("EndDeviceLorawanMac", LOG_LEVEL_ALL);
  // LogComponentEnable ("ClassAEndDeviceLorawanMac", LOG_LEVEL_ALL);
  // LogComponentEnable ("GatewayLorawanMac", LOG_LEVEL_ALL);
  // LogComponentEnable ("LogicalLoraChannelHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("LogicalLoraChannel", LOG_LEVEL_ALL);
  // LogComponentEnable ("LoraHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("LoraPhyHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("LorawanMacHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("OneShotSenderHelper", LOG_LEVEL_ALL);
  // LogComponentEnable ("OneShotSender", LOG_LEVEL_ALL);
  // LogComponentEnable ("PeriodicSender", LOG_LEVEL_ALL);
  // LogComponentEnable ("LorawanMacHeader", LOG_LEVEL_ALL);
  // LogComponentEnable ("LoraFrameHeader", LOG_LEVEL_ALL);

  LogComponentEnableAll (LOG_PREFIX_FUNC);
  LogComponentEnableAll (LOG_PREFIX_NODE);
  LogComponentEnableAll (LOG_PREFIX_TIME);
  // Set SF
  Config::SetDefault ("ns3::EndDeviceLorawanMac::DataRate", UintegerValue (dr));
  Config::SetDefault ("ns3::EndDeviceLorawanMac::MacTxIfEnergyOk", BooleanValue (false));

  // Select harvester and input file
  bool enableVariableHarvester; 
  std::string filenameHarvester;
  if (eh == -1) // sunny
    {
      enableVariableHarvester = true;
      filenameHarvester = pathToInputFile + filenameHarvesterSun;
    }
  else if (eh == -2) // cloudy
    {
      enableVariableHarvester = true;
      filenameHarvester = pathToInputFile + filenameHarvesterCloudy;
    }
  else // uniform harvester
    {
      enableVariableHarvester = false;
    }

  /************************
  *  Create the channel  *
  ************************/

  // NS_LOG_INFO ("Creating the channel...");

  // Create the lora channel object
  Ptr<LogDistancePropagationLossModel> loss = CreateObject<LogDistancePropagationLossModel> ();
  loss->SetPathLossExponent (3.76);
  loss->SetReference (1, 7.7);

  Ptr<PropagationDelayModel> delay = CreateObject<ConstantSpeedPropagationDelayModel> ();

  Ptr<LoraChannel> channel = CreateObject<LoraChannel> (loss, delay);

  /************************
  *  Create the helpers  *
  ************************/

  // NS_LOG_INFO ("Setting up helpers...");

  MobilityHelper mobility;
  Ptr<ListPositionAllocator> allocator = CreateObject<ListPositionAllocator> ();
  allocator->Add (Vector (100,0,0));
  allocator->Add (Vector (0,0,0));
  mobility.SetPositionAllocator (allocator);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");

  // Create the LoraPhyHelper
  LoraPhyHelper phyHelper = LoraPhyHelper ();
  phyHelper.SetChannel (channel);

  // Create the LorawanMacHelper
  LorawanMacHelper macHelper = LorawanMacHelper ();

  // Create the LoraHelper
  LoraHelper helper = LoraHelper ();
  helper.EnablePacketTracking ();

  /************************
  *  Create End Devices  *
  ************************/

  // NS_LOG_INFO ("Creating the end device...");

  // Create a set of nodes
  NodeContainer endDevices;
  endDevices.Create (1);

  // Assign a mobility model to the node
  mobility.Install (endDevices);

  // Create the LoraNetDevices of the end devices
  phyHelper.SetDeviceType (LoraPhyHelper::ED);
  macHelper.SetDeviceType (LorawanMacHelper::ED_A);
  NetDeviceContainer endDevicesNetDevices = helper.Install (phyHelper, macHelper, endDevices);

  // Set message type (Default is unconfirmed)
  if (confirmed)
    {
      Ptr<LorawanMac> edMac1 =
        endDevices.Get (0)->GetDevice (0)->GetObject<LoraNetDevice> ()->GetMac ();
      Ptr<ClassAEndDeviceLorawanMac> edLorawanMac1 = edMac1->GetObject<ClassAEndDeviceLorawanMac> ();
      edLorawanMac1->SetMType (LorawanMacHeader::CONFIRMED_DATA_UP);
    }

  /*********************
   *  Create Gateways  *
   *********************/

  // NS_LOG_INFO ("Creating the gateway...");
  NodeContainer gateways;
  gateways.Create (1);

  mobility.SetPositionAllocator (allocator);
  mobility.Install (gateways);

  // Create a netdevice for each gateway
  phyHelper.SetDeviceType (LoraPhyHelper::GW);
  macHelper.SetDeviceType (LorawanMacHelper::GW);
  helper.Install (phyHelper, macHelper, gateways);

  // macHelper.SetSpreadingFactorsUp (endDevices, gateways, channel);


  /*********************************************
   *  Install applications on the end devices  *
   *********************************************/

  if (sender == "energyAwareSender")
    {
      EnergyAwareSenderHelper energyAwareSenderHelper;
      double voltageTh = 0.2;
      double energyTh =capacitance/1000 * pow (voltageTh, 2) / 2;
      energyAwareSenderHelper.SetEnergyThreshold (energyTh); // (0.29);
      energyAwareSenderHelper.SetMinInterval (Seconds (appPeriod));
      energyAwareSenderHelper.SetPacketSize (19);
      energyAwareSenderHelper.Install (endDevices);
    }
  else if (sender == "multipleShots")
    {
      OneShotSenderHelper oneshotsenderHelper;
      double sendTime = appPeriod;
      while (sendTime < simTime)
      {
        oneshotsenderHelper.SetSendTime (Seconds (sendTime));
        oneshotsenderHelper.Install(endDevices);
        oneshotsenderHelper.SetAttribute ("PacketSize", IntegerValue(packetSize));
        sendTime = sendTime + appPeriod;
        
      }
    }
  else if (sender == "periodicSender")
    {
      PeriodicSenderHelper periodicSenderHelper;
      periodicSenderHelper.SetPeriod (Seconds (appPeriod));
      periodicSenderHelper.SetPacketSize (packetSize);
      periodicSenderHelper.Install (endDevices);
    }

  /************************
   * Install Energy Model *
   ************************/


  CapacitorEnergySourceHelper capacitorHelper;
  capacitorHelper.Set ("Capacitance", DoubleValue (capacitance/1000));
  capacitorHelper.Set ("CapacitorLowVoltageThreshold", DoubleValue (0.545454)); // 1.8 V
  capacitorHelper.Set ("CapacitorHighVoltageThreshold", DoubleValue (0.9090)); // 3 V
  capacitorHelper.Set ("CapacitorMaxSupplyVoltageV", DoubleValue (3.3));
  // Assumption that the C does not reach full capacitance because of some
  // consumption in the OFF state
  double E = 3.3; // V
  double Ioff = 0.0000055;
  double RLoff = E/Ioff;
  double ri = pow(E, 2)/eh;
  double Req_off = RLoff;
  double V0 = E;
  if (eh != 0)
  {
    Req_off = RLoff * ri / (RLoff + ri);
    V0 = E * Req_off / ri;
    }
  NS_LOG_DEBUG ("Initial voltage [V]= " << V0 <<
                " RLoff " << RLoff <<
                " ri " << ri <<
                " R_eq_off " << Req_off);
  // V0 = 1.805;
  std::string rv = "ns3::UniformRandomVariable[Min=" + std::to_string (V0) + "|Max=" + std::to_string (V0) + "]";
  Config::SetDefault ("ns3::CapacitorEnergySource::RandomInitialVoltage", StringValue (rv));
  capacitorHelper.Set ("PeriodicVoltageUpdateInterval", TimeValue (MilliSeconds (500)));
  capacitorHelper.Set ("FilenameVoltageTracking",
                      StringValue(filenameRemainingVoltage));

  LoraRadioEnergyModelHelper radioEnergy;
  radioEnergy.Set("EnterSleepIfDepleted", BooleanValue(false));
  radioEnergy.Set ("TurnOnDuration",
                   TimeValue (Seconds (0.3)));
  radioEnergy.Set ("TurnOnCurrentA", DoubleValue(0.015));
  // Values from datasheet
  // radioEnergy.Set ("TxCurrentA", DoubleValue (0.028)); // check - there are different values
  // radioEnergy.Set ("IdleCurrentA", DoubleValue (0.0000015));
  // radioEnergy.Set ("RxCurrentA", DoubleValue (0.011));
  // radioEnergy.Set ("SleepCurrentA", DoubleValue (0.0000001));
  // radioEnergy.Set ("StandbyCurrentA", DoubleValue (0.0000014));
  // // Values for MCU + Radio (MCU=11uA for active, 5.5uA idle)
  radioEnergy.Set ("TxCurrentA", DoubleValue (0.028011)); 
  radioEnergy.Set ("IdleCurrentA", DoubleValue (0.000007));
  radioEnergy.Set ("RxCurrentA", DoubleValue (0.011011));
  radioEnergy.Set ("SleepCurrentA", DoubleValue (0.0000056));
  radioEnergy.Set ("StandbyCurrentA", DoubleValue (0.0105055));
  radioEnergy.Set ("OffCurrentA", DoubleValue (0.0000055));
  radioEnergy.Set ("ReferenceVoltage", DoubleValue(V0));

  //  // Basic Energy harvesting
  BasicEnergyHarvesterHelper harvesterHelper;
  harvesterHelper.Set ("PeriodicHarvestedPowerUpdateInterval",
                       TimeValue (Seconds(10)));
  // // Visconti, Paolo, et al."An overview on state-of-art energy harvesting
  // //     techniques and choice criteria: a wsn node for goods transport and
  // //     storage powered by a smart solar-based eh system." Int.J .Renew.Energy Res
  // //     7(2017) : 1281 - 1295.
  // // Let's assume we are OUTDOOR, and the surface we are provided is 2 cm2
  // double minPowerDensity = 0.000001; // 30e-3;
  // double maxPowerDensity = 0.00001; // 0.30e-3;
  double minPowerDensity = eh; // 30e-3;
  double maxPowerDensity = eh; // 0.30e-3;
  std::string power = "ns3::UniformRandomVariable[Min=" + std::to_string(minPowerDensity) + "|Max=" + std::to_string(maxPowerDensity) + "]";
  harvesterHelper.Set ("HarvestablePower", StringValue (power));

  // // Variable energy harvesting
  VariableEnergyHarvesterHelper variableEhHelper;
  variableEhHelper.Set("Filename", StringValue(filenameHarvester));


  // install source on EDs' nodes
  EnergySourceContainer sources = capacitorHelper.Install (endDevices);
  // install device model
  DeviceEnergyModelContainer deviceModels =
    radioEnergy.Install (endDevicesNetDevices, sources);

  Names::Add ("/Names/EnergySource", sources.Get(0));

  if (enableVariableHarvester)
  {
    EnergyHarvesterContainer harvesters = variableEhHelper.Install (sources);
  }
  else
    {
      EnergyHarvesterContainer harvesters = harvesterHelper.Install (sources);
    }


  // Names::Add("Names/EnergyHarvester", harvesters.Get (0));
  // Ptr<EnergyHarvester> myHarvester = harvesters.Get(0);
  // myHarvester -> TraceConnectWithoutContext("TotalEnergyHarvested",
  //                                           MakeCallback(&OnEnergyHarvested));


  ///////////////////////
  // Connect tracesources
  ///////////////////////

  Names::Add("Names/node0", endDevices.Get(0)->GetApplication(0));
  ns3::Config::ConnectWithoutContext("/Names/node0/GeneratedPacket",
                                     MakeCallback(&OnGeneratedPacket));

  Ptr<LoraNetDevice> loraDevice = endDevices.Get (0)->GetDevice (0)->GetObject<LoraNetDevice> ();
  Ptr<EndDeviceLorawanMac> myEDmac = loraDevice->GetMac ()->GetObject<EndDeviceLorawanMac> ();
  Ptr<EndDeviceLoraPhy> myEDphy = loraDevice->GetPhy ()->GetObject<EndDeviceLoraPhy> ();

  myEDmac->TraceConnectWithoutContext ("EnoughEnergyToTx",
                                       MakeCallback(&CheckEnoughEnergyCallback));
  myEDphy -> TraceConnectWithoutContext("EndDeviceState",
                                        MakeCallback (&OnEndDeviceStateChange));
  ns3::Config::ConnectWithoutContext ("/Names/EnergySource/RemainingEnergy",
                                          MakeCallback (&OnRemainingEnergyChange));
  // ns3::Config::ConnectWithoutContext ("/Names/EnergySource/RemainingVoltage",
  //                                     MakeCallback (&OnRemainingVoltageChange));
  deviceModels.Get(0)->TraceConnectWithoutContext("TotalEnergyConsumption",
                                           MakeCallback(&OnDeviceEnergyConsumption));

  ////////////
  // Create NS
  ////////////

  NodeContainer networkServers;
  networkServers.Create (1);

  // Install the NetworkServer application on the network server
  NetworkServerHelper networkServerHelper;
  networkServerHelper.SetGateways (gateways);
  networkServerHelper.SetEndDevices (endDevices);
  networkServerHelper.Install (networkServers);

  // Install the Forwarder application on the gateways
  ForwarderHelper forwarderHelper;
  forwarderHelper.Install (gateways);

  ///////////////////
  // Packet tracker
  ///////////////////
  LoraPacketTracker& tracker = helper.GetPacketTracker();


  /****************
  *  Simulation  *
  ****************/

  Simulator::Stop (Seconds (simTime));

  Simulator::Run ();

  // Outputs
  std::string pdr = tracker.CountMacPacketsGlobally (Seconds(0), Seconds(simTime));
  std::string cpsr = "0 0";
  if (confirmed)
  {
    cpsr = tracker.CountMacPacketsGloballyCpsr (Seconds(0), Seconds(simTime));
  }
  std::cout << generatedPacketsAPP << " " << pdr << " " << cpsr << std::endl;
  // std::vector<double> timeStatistics = tracker.TxTimeStatisticsPerEd (Seconds(0),
                                                                      // Seconds(simTime),
                                                                      // 0);
  // std::cout << std::to_string (timeStatistics[0]) << " "
  //           << std::to_string (timeStatistics[1]) << " " 
  //           << std::to_string (timeStatistics[2]) << " " << std::endl;

  // Avoid non-existent files
  NS_LOG_DEBUG ("Create file if not done yet: " << stateChangeCallbackFirstCall);
  // Fix output files if not created
  if (stateChangeCallbackFirstCall)
    {
      const char *c = filenameState.c_str ();
      std::ofstream outputFile;
      // Delete contents of the file as it is opened 
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      // Set the initial sleep state
      outputFile << 0 << " " << 0 << std::endl;
      NS_LOG_DEBUG ("Append initial state");
      stateChangeCallbackFirstCall = false;
      outputFile.close ();
    }

  if (energyConsumptionCallbackFirstCall)
    {
      const char *c = filenameEnergyConsumption.c_str ();
      std::ofstream outputFile;
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      // Set the initial sleep state
      outputFile << 0 << " " << 0 << std::endl;
      NS_LOG_DEBUG ("Append initially not enough energy, because never called");
      energyConsumptionCallbackFirstCall = false;
      outputFile.close ();
    }

  if (enoughEnergyCallbackFirstCall)
    {
      const char *c = filenameEnoughEnergy.c_str ();
      std::ofstream outputFile;
      // Delete contents of the file as it is opened
      outputFile.open (c, std::ofstream::out | std::ofstream::trunc);
      // Set the initial
      outputFile << 0 << " " << 0 << std::endl;
      NS_LOG_DEBUG ("Append initially not enough energy, because never called");
      enoughEnergyCallbackFirstCall = false;
      outputFile.close ();
    }

  // Destroy simulator
  Simulator::Destroy ();

  return 0;
}
