<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%> <!-- Add this import statement -->

<!DOCTYPE html>
<html>
<head>
    <title>Student List</title>
    <!-- Add Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <style>
        /* Add custom CSS for highlighting rows on hover */
        .table tbody tr:hover {
            background-color: #f8f9fa;
            cursor: pointer;
        }
    </style>
</head>
<body>
<div class="container mt-5">
    <h1>Welcome to Student List</h1>
    <p>This is a list of students in the system.</p>
    <div>
        <jsp:include page="options.jsp"/>
    </div>
    <table class="table mt-3">
        <thead class="thead-dark">
        <tr>
            <th scope="col">ID</th>
            <th scope="col">Name</th>
            <th scope="col">Semester</th>
            <th scope="col">CGPA</th>
            <th></th>
        </tr>
        </thead>
        <tbody>
        <%-- Loop through the list of students and display each student as a row in the table --%>
        <c:forEach var="student" items="${studentList}">
            <tr>
                <td>${student.studentId}</td>
                <td>${student.name}</td>
                <td>${student.semester}</td>
                <td>${student.cgpa}</td>
                <td>
                    <form method="post" action="http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/update-student.jsp">
                        <input name="studentId" value="${student.studentId}" hidden="hidden">
                        <input name="name" value="${student.name}" hidden="hidden">
                        <input name="semester" value="${student.semester}" hidden="hidden">
                        <input name="cgpa" value="${student.cgpa}" hidden="hidden">
                        <input type="submit" value="Update" class="btn btn-primary" >
                    </form>
                </td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>
</body>
</html>
