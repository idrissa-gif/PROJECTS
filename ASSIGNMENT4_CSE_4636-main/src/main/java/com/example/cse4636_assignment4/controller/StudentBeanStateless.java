package com.example.cse4636_assignment4.controller;

import com.example.cse4636_assignment4.Repository.StudentRepository;
import com.example.cse4636_assignment4.model.Student;

import javax.ejb.Stateless;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.constraints.Null;
import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Request;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.UriBuilder;
import java.io.IOException;
import java.net.URI;
import java.net.URL;

@Stateless
@Path("/Stateless/student")
public class StudentBeanStateless {

    private StudentRepository studentRepository = new StudentRepository(); // Inject the service to handle database operations

    @POST
    @Path("/add")
    @Produces(MediaType.TEXT_HTML)
    public Response addStudent(@FormParam("name") String name, @FormParam("semester") int semester, @FormParam("cgpa") double cgpa) {
        Student student = new Student(name, semester, cgpa);

        studentRepository.add(student); // Call the service to add student to the database

        // Redirect to index.jsp after adding student
        URI uri = UriBuilder.fromUri("http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/").build();
        return  Response.seeOther(uri).build();

    }

    @POST
    @Path("/add/UsingQueryParam")
    @Produces(MediaType.TEXT_HTML)
    public Response addStudentUsingParamQuery(@QueryParam("name") String name, @QueryParam("semester") int semester, @QueryParam("cgpa") double cgpa) {
        Student student = new Student(name, semester, cgpa);

        studentRepository.add(student); // Call the service to add student to the database

        // Redirect to index.jsp after adding student
        URI uri = UriBuilder.fromUri("http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/").build();
        return  Response.seeOther(uri).build();

    }

    @GET
    @Path("/find/{studentId}")
    @Produces(MediaType.APPLICATION_JSON)

    public Response getStudentInfo(@PathParam("studentId") Long studentId){

        // Create a Student object with retrieved student details
        Student student = studentRepository.find(studentId);
        System.out.println(student.getStudentId()+" "+student.getName()+" "+student.getSemester()+" "+student.getCgpa());
        return Response.ok(student).build();
    }

    @GET
    @Path("/compareCgpa")
    @Produces(MediaType.APPLICATION_JSON)
    public Response getStudentWithHigherCgpa(
            @QueryParam("studentId1") long studentId1,
            @QueryParam("studentId2") long studentId2
    ) {
        Student student1 = studentRepository.find(studentId1); // Call the service to get student1 from the database
        Student student2 = studentRepository.find(studentId2); // Call the service to get student2 from the database

        // Compare CGPAs and return the student with higher CGPA
        if (student1.getCgpa() > student2.getCgpa()) {
            return Response.ok(student1).build();
        } else {
            return Response.ok(student2).build();
        }
    }

    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Path("/update")
    public Response updateStudentName(
            @FormParam("studentId") Long studentId,
            @FormParam("name") String name,
            @FormParam("semester") int semester,
            @FormParam("cgpa") float cgpa
    ) {
        Student student = new Student(studentId,name,semester,cgpa);
        studentRepository.update(student); // Call the service to update student name in the database
        URI uri = UriBuilder.fromUri("http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/").build();
        return  Response.seeOther(uri).build();
    }
}

