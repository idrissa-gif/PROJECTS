package rmi;
import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class Bank extends UnicastRemoteObject implements BankInterface{
    private int account_number= 1900412 ;
    private  String account_name = "Idrissa";
    private float balance = 100000000.82F;

    protected Bank() throws RemoteException {
    }

    public int getaccount_number() throws RemoteException
    {
        return this.account_number;
    }
    public String getAccount_name() throws RemoteException
    {
        return this.account_name;
    }
    public String withdraw(float amount) throws RemoteException{
        if (this.balance <= amount)
        {
            return "Your balance is insufficient for withdrawing "+ amount + "\nyour current count is: " + this.balance;
        }else {
            this.balance -= amount;
            return "You have withdrawing "+ amount + " from balance and your current count is: " + this.balance;
        }
    }
    public String deposit(float amount) throws RemoteException
    {
        this.balance += amount;
        return "Your deposit was successfully created Current Account is: " + this.balance;
    }

    public float getbalance() throws RemoteException{
        return this.balance;
    }

    public void setAccount_number(int account_number) throws RemoteException{
        this.account_number = account_number;
    }

    public void setAccount_name(String account_name) throws RemoteException{
        this.account_name = account_name;
    }

    public void setBalance(float balance) throws RemoteException
    {
        this.balance = balance;
    }

}
