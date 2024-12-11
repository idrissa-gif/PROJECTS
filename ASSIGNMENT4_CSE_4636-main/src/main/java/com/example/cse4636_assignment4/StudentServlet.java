package com.example.cse4636_assignment4;

// StudentServlet.java

import com.example.cse4636_assignment4.Repository.StudentRepository;
import com.example.cse4636_assignment4.model.Student;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/student")
public class StudentServlet extends HttpServlet {

    private StudentRepository studentRepository = new StudentRepository();

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Fetch all students from the database
        List<Student> studentList = studentRepository.getStudentWithCriteriaBuilder();

        System.out.println(studentList);
        // Pass the students as a request attribute
        request.setAttribute("studentList", studentList);


        // Forward to the index.jsp file
        request.getRequestDispatcher("/index.jsp").forward(request, response);
    }

    // Other methods for handling POST requests and other functionalities

}

