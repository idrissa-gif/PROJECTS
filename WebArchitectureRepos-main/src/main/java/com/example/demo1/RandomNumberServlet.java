package com.example.demo1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.random.RandomGenerator;

public class RandomNumberServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int n1 = Integer.parseInt(req.getParameter("lowerbound")) ;
        int n2 = Integer.parseInt(req.getParameter("upperbound"));
        int lowerbound= n1 > n2 ? n2 : n1;
        int upperbound= n1 >= n2 ? n1 : n2;
        int randomNumber  = RandomGenerator.getDefault().nextInt(lowerbound,upperbound);
        PrintWriter out = resp.getWriter();
        out.println("<html><body>");
        out.println("<p>Random between " + n1 + " and " + n2 + " is " + randomNumber +"  </p>");
        out.println("</body></html>");

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
