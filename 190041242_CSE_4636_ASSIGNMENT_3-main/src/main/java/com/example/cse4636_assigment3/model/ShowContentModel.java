package com.example.cse4636_assigment3.model;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class ShowContentModel {
    public ResultSet ShowShoppingCartContent()
    {
        try {
            DBConnection connection = new DBConnection();
            Connection con = connection.getCon();
            String query = "select  * from shopping_cart";
            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery(query);
            return rs;
        }catch (SQLException e)
        {
            System.out.println(e);
        }
     return null;
    }

}
