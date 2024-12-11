<%--
  Created by IntelliJ IDEA.
  User: idrissamahamoudoudicko
  Date: 14/4/2023
  Time: 11:50
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
  <title>Student with Highest CGPA</title>
  <!-- Include Bootstrap CSS -->
  <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container mt-4">
  <h1>Student with Highest CGPA</h1>
  <div>
    <jsp:include page="options.jsp"/>
  </div>
  <button type="button" class="btn btn-primary" id="getHighestCgpaBtn">Get Student with Highest CGPA</button>
  <div class="mt-4" id="studentInfo">
    <h2>Student Information</h2>
    <p><strong>Student ID:</strong> <span id="studentId"></span></p>
    <p><strong>Student Name:</strong> <span id="studentName"></span></p>
    <p><strong>Semester:</strong> <span id="semesterLabel"></span></p>
    <p><strong>Student CGPA:</strong> <span id="studentCgpa"></span></p>
  </div>
</div>

<!-- Include jQuery library -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<!-- Include Bootstrap JS -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

<!-- AJAX call to the RESTful API endpoint -->
<script>
  $(document).ready(function() {
    $("#getHighestCgpaBtn").click(function() {
      $.ajax({
        url: "http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/api/Singleton/student/highest-cgpa", // replace with your actual API endpoint
        type: "GET",
        dataType: "json",
        success: function(data) {
          // Update the student information on the page
          $("#studentName").text(data.name);
          $("#studentId").text(data.studentId);
          $("#studentCgpa").text(data.cgpa);
          $("#semesterLabel").text(data.semester);
        },
        error: function() {
          // Show error message on the page
          $("#studentInfo").html("<p>Error occurred while retrieving student information.</p>");
        }
      });
    });
  });
</script>
</body>
</html>

