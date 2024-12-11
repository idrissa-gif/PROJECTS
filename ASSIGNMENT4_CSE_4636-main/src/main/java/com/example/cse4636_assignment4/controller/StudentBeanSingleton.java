package com.example.cse4636_assignment4.controller;

import com.example.cse4636_assignment4.Repository.StudentRepository;
import com.example.cse4636_assignment4.model.Student;

import javax.ejb.Singleton;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.List;

@Singleton
@Path("/Singleton/student")
public class StudentBeanSingleton {
    private StudentRepository studentRepository = new StudentRepository();

    @GET
    @Path("/highest-cgpa")
    @Produces(MediaType.APPLICATION_JSON)
    public Response getStudentWithHighestCGPA() {
        // Retrieve student with highest CGPA from database
        List<Student> students = studentRepository.findTheHighestCgpa();

        if (students != null && !students.isEmpty()) {
            return Response.ok(students.get(0)).build();
        } else {
            return Response.status(Response.Status.NOT_FOUND).build();
        }
    }
}
