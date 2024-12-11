package com.example.demo1;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class AdditionServlet extends HttpServlet {
    public void init(){}
    public void doGet(HttpServletRequest request , HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        int num1 = Integer.parseInt(request.getParameter("number1"));
        int num2 = Integer.parseInt(request.getParameter("number2"));
        int sum = num1+num2;
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<p>Hello</p>");
        out.println("<h1> Addition "+num1+" + "+num2+" = "+sum+"</h1>");
        out.println("</html></body>");
    }

    public void doPost(HttpServletRequest request , HttpServletResponse response) throws IOException {
    }
    public void destroy(){}
}
