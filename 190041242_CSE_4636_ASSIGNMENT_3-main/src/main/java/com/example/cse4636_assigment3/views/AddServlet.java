package com.example.cse4636_assigment3.views;

import com.example.cse4636_assigment3.BeanClass.Product;
import com.example.cse4636_assigment3.controller.ShoppingCartController;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class AddServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ShoppingCartController cartController = new ShoppingCartController();
        Product shoppingCart = new Product();
        shoppingCart.setProductName(req.getParameter("product_name"));
        shoppingCart.setPrice(Integer.valueOf(req.getParameter("price")));
        shoppingCart.setQuantity(Integer.valueOf(req.getParameter("quantity")));
        shoppingCart.setImage(req.getParameter(req.getParameter("image")));
        PrintWriter out = resp.getWriter();

        if(cartController.add(shoppingCart) == true)
        {
            out.println("<body><h1>Successfully Added</h1></body>");
        }
        else {
            out.println("<h1>Failed to add to the cart</h1>");
        }
        RequestDispatcher rd = req.getRequestDispatcher("AddToCart.jsp");
        rd.include(req,resp);
    }
}
