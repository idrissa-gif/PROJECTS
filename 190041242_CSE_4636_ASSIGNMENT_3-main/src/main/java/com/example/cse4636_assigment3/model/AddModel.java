package com.example.cse4636_assigment3.model;

import com.example.cse4636_assigment3.BeanClass.Product;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class AddModel {
    public boolean AddToCart(Product shoppingCart)
    {
        try {
            DBConnection connection = new DBConnection();
            Connection con = connection.getCon();
            String query = "insert into shopping_cart(product_name,price,quantity,image) values('"+shoppingCart.getProductName()+"',"+shoppingCart.getPrice()+","+shoppingCart.getQuantity()+",'"+shoppingCart.getImage()+"')";
            Statement statement = con.createStatement();
            int status = statement.executeUpdate(query);
            if(status>0)
            {
                return true;
            }
        }catch (SQLException e)
        {
            System.out.println(e);
        }


        return false;
    }

}
