package com.example.cse4636_assigment3.model;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnection{
    /**
     * This method will essentially communicate with the backend
     * database server and get the information that the user has
     * requested and want to store.
     **/

    private Connection con;

    public DBConnection() {
        DBconnection();
    }
    /** This Function is used to connect the Database in
     * This is application I am using the MysqlWorkbench**/
    public void DBconnection()
    {
        try{
            System.out.println("Hello Macke");
            Class.forName("com.mysql.cj.jdbc.Driver");
            this.con= DriverManager.getConnection("jdbc:mysql://localhost:3306/CSE_4636_ASSIGMENT_3","root","admin123");
            /** here CSE_4636_ASSIGMENT_3 is database name, root is username and is admin123 password **/
        }catch(Exception e){ System.out.println(e);}
    }

    public Connection getCon() {
        return con;
    }

    public void setCon(Connection con) {
        this.con = con;
    }
}
