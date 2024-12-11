package com.example.cse_4636_assignment;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class AddItemToCartServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String ItemId = req.getParameter("ItemId");
        String Itemname = req.getParameter("ItemName");
        String price = req.getParameter("price");
        HttpSession session = req.getSession();
        ArrayList<ArrayList<String>> cartArray = (ArrayList<ArrayList<String>>) session.getAttribute("cart");
        PrintWriter out = resp.getWriter();
        Boolean flag = false;
        if (cartArray == null)
        {
            cartArray = new ArrayList<>();
        }
        for (int i= 0 ; i<cartArray.size() ; i++)
        {
            if (cartArray.get(i).get(0).equals(ItemId)){
                out.println("<h1> Product is alright Added in your Shopping Cart</h1>");
                flag = true;
            }
        }
        if (!flag) {
            cartArray.add(new ArrayList<>(Arrays.asList(ItemId, Itemname, price, "1")));
            session.setAttribute("cart", cartArray);
            out.println("<h1> Product Successfully Added </h1>");
        }
        RequestDispatcher rd = req.getRequestDispatcher("homepage.jsp");
        rd.include(req, resp);

    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
