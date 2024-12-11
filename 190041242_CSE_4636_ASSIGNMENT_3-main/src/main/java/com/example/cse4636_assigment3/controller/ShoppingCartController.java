package com.example.cse4636_assigment3.controller;

import com.example.cse4636_assigment3.BeanClass.Product;
import com.example.cse4636_assigment3.model.AddModel;
import com.example.cse4636_assigment3.model.ShowContentModel;

import java.sql.ResultSet;

public class ShoppingCartController {
    private AddModel addModel = new AddModel();
    private ShowContentModel showContentModel = new ShowContentModel();

    public boolean add(Product shoppingCart)
    {
        return addModel.AddToCart(shoppingCart);
    }
    public ResultSet showContent()
    {
        return  showContentModel.ShowShoppingCartContent();
    }
}
