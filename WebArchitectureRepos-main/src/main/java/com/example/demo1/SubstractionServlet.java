package com.example.demo1;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name="SubstractionServlet", value = "/substraction")

public class SubstractionServlet extends HttpServlet {
    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int n1 = Integer.parseInt(req.getParameter("number1"));
        int n2 = Integer.parseInt(req.getParameter("number2"));
        int diff = n1-n2;
        PrintWriter out = resp.getWriter();
        out.println("<html><body>");
        out.println("<p>Hello</p>");
        out.println("<h1> Addition "+n1+" - "+n2+" = "+diff+"</h1>");
        out.println("</html></body>");
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
