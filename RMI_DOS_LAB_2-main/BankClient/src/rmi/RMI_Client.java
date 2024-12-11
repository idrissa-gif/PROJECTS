/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmi;

/**
 *
 * @author Youssouf
 */
import java.rmi.*;
import java.io.*;

public class RMI_Client {

    public static String s;

    public static void main(String args[]) throws Exception {

        var remoteobject = (BankInterface) Naming.lookup("rmi://localhost:1242/BANK");
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        System.out.println("ENTER Your Account NUMBER:");
        System.out.println("ENTER Your Account Name:");
        float amount =  0.0F;

        do {
            System.out.println("*****ENTER YOUR CHOICE*****");
            System.out.println("1.getAccountNumber");
            System.out.println("2.getAccountName");
            System.out.println("3.getBalance");
            System.out.println("4.withdraw");
            System.out.println("5.deposit");
            int c = Integer.parseInt(br.readLine());
            switch (c) {
                case 1:
                    int ans1 = remoteobject.getaccount_number();
                    System.out.println("You Account number is: " + ans1);
                    break;
                case 2:
                    String ans2 = remoteobject.getAccount_name();
                    System.out.println("Your Account name is: " + ans2);
                    break;
                case 3:
                    float ans3 = remoteobject.getbalance();
                    System.out.println("Your Current Balance is: " + ans3);
                    break;
                case 4:
                    System.out.println("Enter the Amount to withdraw: ");
                    amount = Float.parseFloat(br.readLine());
                    System.out.println(remoteobject.withdraw(amount));
                    break;
                case 5:
                    System.out.println("Enter the Amount to deposit:");
                    amount = Float.parseFloat(br.readLine());
                    System.out.println( remoteobject.deposit(amount));
                    break;
            }
            //System.out.println(remoteobject.test());
            System.out.println("DO YOU WANT TO CONTINUE?Y/N");
            s = br.readLine();
        } while (s.equals("y") || s.equals("Y"));
    }
}











