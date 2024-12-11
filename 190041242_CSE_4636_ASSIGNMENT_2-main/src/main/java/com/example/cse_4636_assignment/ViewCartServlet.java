package com.example.cse_4636_assignment;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class ViewCartServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession();
        ArrayList<ArrayList<String>> cartArray= (ArrayList<ArrayList<String>>) session.getAttribute("cart");
        PrintWriter out = resp.getWriter();
        out.println("<h1 align = \"center\">Shopping Cart</h1>");
        if (cartArray==null || cartArray.size()==0)
        {
            out.println("<body><h4>" +
                    "Your Shopping Cart is empty" +
                    "</h4></body>");
        }
        else {
            out.print(
                    "<table  border = \"1\" align = \"center\"> " +
                            "<tr>" +
                            "       <th>Item Id</th> " +
                            "       <th>Item Name</th> " +
                            "       <th>Price</th>" +
                            "       <th>Number of Items</th>" +
                            "       <th>Option</th>" +
                            "</tr>");
            for (int i =0  ; i<cartArray.size() ; i++)
            {
                out.println("<form action=\"EditAndRemove\"><tr>"+
                        "<td > <input name=\"ItemId\" value="+ cartArray.get(i).get(0) + " readonly></td>" +
                        "<td > <input name=\"ItemName\" value="+ cartArray.get(i).get(1) + " readonly></td>" +
                        "<td > <input name=\"price\" value=" + cartArray.get(i).get(2) +" readonly></td>"+
                        "<td > <input name=\"noItems\" value=" + cartArray.get(i).get(3) +"></td>"+
                        "<td > " +
                        "   <input type=\"submit\" name = \"Delete\" value = \"Delete\">" +
                        "   <input type=\"submit\" name = \"Edit\" value = \"Edit\">" +
                        "</td>"+
                        "</tr></form>");
            }
            out.println("</table>");
        }
        out.println("<body>" +
                "<form action=\"homepage.jsp\" align = \"center\">" +
                "<button type = \"submit\">View Items</button>" +
                "</form>" +
                "</body>");
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
