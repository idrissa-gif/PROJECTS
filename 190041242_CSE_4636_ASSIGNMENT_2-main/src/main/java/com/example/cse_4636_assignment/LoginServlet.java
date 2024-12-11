package com.example.cse_4636_assignment;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

//@WebServlet(name = "LoginServlet",value = "/login")
public class LoginServlet extends HttpServlet {
    String _username = "idrissa" , _password = "dicko";

    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String userName = req.getParameter("username-field");
        String passWord = req.getParameter("password-field");
        if (userName.equals(_username) && passWord.equals(_password))
        {
            PrintWriter out = resp.getWriter();
            out.println("<html><body>"+
                    "<h1>Successfully Login !!!</h1>"+
                    "</body></html>");
            RequestDispatcher requestDispatcher = req.getRequestDispatcher("homepage.jsp");
            requestDispatcher.include(req,resp);
        }
        else {
            PrintWriter out = resp.getWriter();
            out.println("<html><body>"+
                    "<h1> Invalid Username or Password </h1>"+
                    "</body></html>");
            RequestDispatcher rd = req.getRequestDispatcher("login.html");
            rd.include(req,resp);
        }
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
