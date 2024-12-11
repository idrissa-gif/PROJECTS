/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmi;

import java.rmi.*;


public interface BankInterface extends Remote {
    public int getaccount_number() throws RemoteException;
    public String getAccount_name() throws RemoteException;
    public String  withdraw(float amount) throws RemoteException;
    public String deposit(float amount) throws RemoteException;
    public float getbalance() throws RemoteException;
    public void setAccount_number(int account_number) throws RemoteException;
    public void setAccount_name(String account_name) throws RemoteException;

    public void setBalance(float balance) throws RemoteException;
    //public String test();
}
