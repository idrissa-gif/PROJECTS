<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Add Student</title>
    <!-- Include Bootstrap CSS -->
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container mt-5">
    <h1>Add Student</h1>
    <div>
        <jsp:include page="options.jsp"/>
    </div>

    <form action="http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/api/Stateless/student/add" method="post">
        <div class="form-group">
            <label for="name">Name:</label>
            <input type="text" id="name" name="name" class="form-control" required>
        </div>
        <div class="form-group">
            <label for="semester">Semester:</label>
            <input type="text" id="semester" name="semester" class="form-control" required>
        </div>
        <div class="form-group">
            <label for="cgpa">CGPA:</label>
            <input type="text" id="cgpa" name="cgpa" class="form-control" required>
        </div>
        <button type="submit" class="btn btn-primary">Add Student</button>
    </form>
</div>
</body>
</html>
