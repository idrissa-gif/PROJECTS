<%--
  Created by IntelliJ IDEA.
  User: idrissamahamoudoudicko
  Date: 12/4/2023
  Time: 21:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
  <title>Update Student</title>
  <!-- Add Bootstrap CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>
<body>
<div class="container mt-5">
  <h1>Update Student</h1>
  <p>Update the information of a student.</p>
  <div>
    <jsp:include page="options.jsp"/>
  </div>
  <form action="http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/api/Stateless/student/update" method="post" class="mt-3">
    <div class="form-group">
      <label for="studentId">Student ID:</label>
      <input type="text" class="form-control" id="studentId" name="studentId" value="<%= request.getParameter("studentId")%>" aria-hidden="false">
    </div>
    <div class="form-group">
      <label for="name">Name:</label>
      <input type="text" class="form-control" id="name" name="name" value="<%=request.getParameter("name")%>" required>
    </div>
    <div class="form-group">
      <label for="semester">Semester:</label>
      <input type="number" class="form-control" id="semester" name="semester" value="<%=request.getParameter("semester")%>" required>
    </div>
    <div class="form-group">
      <label for="cgpa">CGPA:</label>
      <input type="number" step="0.01" class="form-control" id="cgpa" name="cgpa" value="<%=request.getParameter("cgpa")%>" required>
    </div>
    <button type="submit" class="btn btn-primary">Update</button>
  </form>
</div>
</body>
</html>

