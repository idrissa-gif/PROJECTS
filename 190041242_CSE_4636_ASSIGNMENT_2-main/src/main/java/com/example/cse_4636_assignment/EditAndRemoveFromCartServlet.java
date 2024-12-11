package com.example.cse_4636_assignment;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class EditAndRemoveFromCartServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);
        ArrayList<ArrayList<String>> cartArray = (ArrayList<ArrayList<String>>) session.getAttribute("cart");
        String ItemId = req.getParameter("ItemId");
        String ItemName = req.getParameter("ItemName");
        String price = req.getParameter("price");
        String noItems= req.getParameter("noItems");
        PrintWriter out = resp.getWriter();

        if(req.getParameter("Delete")!=null)
        {
            cartArray.remove(Arrays.asList(ItemId,ItemName,price,noItems));
            out.println("<h1>Item Successfully Deleted from Shopping Card</h1>");
        }else if (req.getParameter("Edit")!=null)
        {

            for (int i= 0 ; i<cartArray.size() ; i++)
            {
                if (cartArray.get(i).get(0).equals(ItemId)){
                    String OldItem = cartArray.get(i).get(0);
                    String OldItemName = cartArray.get(i).get(1);
                    String Oldprice = cartArray.get(i).get(2);
                    String OldNoItems = cartArray.get(i).get(3);

                    cartArray.remove(Arrays.asList(OldItem,OldItemName,Oldprice,OldNoItems));
                    cartArray.add(new ArrayList<>(Arrays.asList(ItemId,ItemName,price,noItems)));
                    out.println("<h1>Item Successfully Edited</h1>");
                    break;
                }
            }
        }
        session.setAttribute("cart",cartArray);
        out.println("<body>" +
                "<form action=\"viewCart\" align = \"center\">" +
                "<button type = \"submit\">Shopping Cart</button>" +
                "</form>" +
                "</body>");
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
