#include <iostream>
#include <sstream>
#include <iomanip>

#include <cstdlib>
#include <mysql.h>

#ifndef TEAM_H 
#include "Team.h"
#endif // !TEAM_H

#ifndef FIXTURE_H
#include "Fixture.h"
#endif // !FIXTURE_H

#ifndef STANDINGS_H
#include "Standings.h"
#endif // !STANDINGS_H

#ifndef LEAGUEINFO_H
#include "LeagueInfo.h"
#endif // !LEAGUEINFO_H

#ifndef MENU_H
#include "Menu.h"
#endif // !MENU_H

using namespace std;
using namespace menu;

int main(int argc, char** argv)
{
	int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0, ch5 = 0, ch6 = 0, ch7 = 0, managerid, playerid, pos;
	string tname;
	Team* Teamconn = new Team("localhost", "root", "test123", "leaguedb");
	Manager* Managerconn = new Manager("localhost", "root", "test123", "leaguedb");
	Player* Playerconn = new Player("localhost", "root", "test123", "leaguedb");
	Fixture* Fixtureconn = new Fixture("localhost", "root", "test123", "leaguedb");
	Standings* Standingsconn = new Standings("localhost", "root", "test123", "leaguedb");
	LeagueInfo* LeagueInfoconn = new LeagueInfo("localhost", "root", "test123", "leaguedb");

	while (1)
	{

		ch1 = mainMenu();
		if (ch1 == EXIT) break;

		switch (ch1)
		{
		case CONTINUELEAGUE:
		LEAGUEMENU:
			system("cls");

			while (true)
			{
				ch7 = existingLeagueMenu();
				if (ch7 == V_END) { system("cls"); break; }
				switch (ch7)
				{
				case VIEWSCORES:
					system("cls");
					Fixtureconn->getligue();
					break;
				case STANDINGSTABLE:
					system("cls");
					Standingsconn->getstanding();
					break;
				case MOSTPOINTS:
					system("cls");
					Standingsconn->TeamWithMostPoints();
					getchar();
					getchar();
					system("cls");
					break;
				case MOSTGOALS:
					system("cls");
					Standingsconn->TeamWithMostGoal();
					getchar();
					getchar();
					system("cls");
					break;
				case HIGHDIFF:
					system("cls");
					Standingsconn->TeamWithHighestDifference();
					getchar();
					getchar();
					system("cls");
					break;
				case LEASTPOINTS:
					system("cls");
					Standingsconn->TeamWithLeastPoints();
					getchar();
					getchar();
					system("cls");
					break;
				case LEASTGOALS:
					system("cls");
					Standingsconn->TeamWithLeastGoal();
					getchar();
					getchar();
					system("cls");
					break;
				case LOWDIFF:
					system("cls");
					Standingsconn->TeamWithLowestDifference();
					getchar();
					getchar();
					system("cls");
					break;

				default:
					system("cls");
					cout << "Invalid choice" << endl;
					getchar();
					getchar();
					break;
				}

			}
			break;
		case NEW:
			system("cls");
			ch2 = confirmation();
			while (true)
			{
				if (ch2 == NO) { system("cls"); break; }
				switch (ch2)
				{
				case YES:
					system("cls");
					LeagueInfoconn->setinfo();
					system("cls");


					while (true)
					{
						ch3 = newLeaueMenu();
						if (ch3 == GOBACK) { ch2 = 2; system("cls"); break; }
						switch (ch3)
						{
						case TEAM:
							system("cls");
							while (true)
							{
								ch4 = teamMenu();
								if (ch4 == T_END) break;
								switch (ch4)
								{
								case ADDTEAM:
									system("cls");
									Teamconn->insert();
									getchar();
									getchar();
									system("cls");
									break;
								case PRINTTEAMS:
									system("cls");
									Teamconn->printall();
									system("cls");
									break;
								case EDITTEAM:
									system("cls");
									cout << "\nEnter the Team name: ";
									getchar();
									getline(std::cin, tname);
									Teamconn->edit(tname);
									getchar();
									getchar();
									system("cls");
									break;
								case DELTEAM:
									system("cls");
									getchar();
									cout << "\nEnter the Team name: ";
									getline(std::cin, tname);
									Teamconn->deleteteam(tname);
									getchar();
									getchar();
									system("cls");
									break;
								case SEARCHTEAM:
									system("cls");
									cout << "\nEnter the Team name: ";
									getchar();
									getline(std::cin, tname);
									Teamconn->search(tname);
									getchar();
									getchar();
									system("cls");
									break;
								default:
									cout << "Invalid choice" << endl;
									getchar();
									getchar();
									system("cls");
									break;
								}
							}
							break;
						case MANAGER:
							system("cls");
							while (true)
							{
								ch5 = managerMenu();
								if (ch5 == M_END) { system("cls"); break; }
								switch (ch5)
								{
								case ADDMANAGER:
									system("cls");
									Managerconn->insert();
									getchar();
									getchar();
									system("cls");
									break;
								case PRINTMANAGERS:
									system("cls");
									Managerconn->printall();
									
									system("cls");
									break;
								case EDITMANAGER:
									system("cls");
									cout << "\nEnter the Manager Id: ";
									cin >> managerid;
									Managerconn->edit(managerid);
									getchar();
									getchar();
									system("cls");
									break;
								case DELMANAGER:
									system("cls");
									cout << "\nEnter the Manager id: ";
									cin >> managerid;
									Managerconn->deleteteam(managerid);
									getchar();
									getchar();
									system("cls");
									break;
								case SEARCHMANAGER:
									system("cls");
									cout << "\nEnter the Manager id: ";
									cin >> managerid;
									Managerconn->search(managerid);
									getchar();
									getchar();
									system("cls");
									break;
								default:
									cout << "Invalid choice" << endl;
									getchar();
									getchar();
									system("cls");
									break;
								}
							}
							break;
						case PLAYER:
						system("cls");
							while (true)
							{
								ch6 = playerMenu();
								if (ch6 == P_END) { system("cls"); break; }
								switch (ch6)
								{
								case ADDPLAYER:
									system("cls");
									checkposition();
									getchar();
									getchar();
									system("cls");
									break;
								case PRINTPLAYERS:
									system("cls");
									Playerconn->printall();
									
									system("cls");
									break;
								case EDITMANAGER:
									system("cls");
									cout << "Enter the player id: ";
									cin >> playerid;
									Playerconn->editplayer(playerid);
									getchar();
									getchar();
									system("cls");
									break;
								case DELPLAYER:
									system("cls");
									cout << "Enter the player id: ";
									cin >> playerid;
									Playerconn->deleteplayer(playerid);
									getchar();
									getchar();
									system("cls");
									break;
								case SEARCHPLAYER:
									system("cls");
									cout << "Enter the player id: ";
									cin >> playerid;
									Playerconn->searchplayer(playerid);
									getchar();
									getchar();
									system("cls");
									break;
								default:
									cout << "Invalid choice" << endl;
									getchar();
									getchar();
									system("cls");
									break;
								}
							}
							break;
						case STARTLEAGUE:
							system("cls");
							Fixtureconn->generateSchedule();
							Standingsconn->updateStandingsTable();
							LeagueInfoconn->setNoOFTeam();

							goto  LEAGUEMENU;

							break;
						default:
							cout << "Invalid choice" << endl;
							getchar();
							getchar();
							system("cls");
							break;
						}
						system("cls");
	//					break;
					}
					system("cls");
					break;
				default:
					cout << "Invalid choice" << endl;
					getchar();
					getchar();
					system("cls");
					break;

				}


			}
			system("cls");
			break;
		default:
			cout << "Invalid choice" << endl;
			getchar();
			getchar();
			system("cls");
			break;
		}
	}
	return 0;
}