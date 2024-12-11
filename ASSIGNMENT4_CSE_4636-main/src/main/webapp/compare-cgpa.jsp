<%--
  Created by IntelliJ IDEA.
  User: idrissamahamoudoudicko
  Date: 12/4/2023
  Time: 01:39
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <title>Student Comparison</title>
    <!-- Include Bootstrap CSS -->
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div>
    <jsp:include page="options.jsp"/>
</div>
<div class="container mt-4">
    <h1>Student Comparison</h1>
    <form>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="studentId1">Student 1 ID</label>
                <input type="text" class="form-control" id="studentId1" name="studentId1" placeholder="Enter Student 1 ID">
            </div>
            <div class="form-group col-md-6">
                <label for="studentId2">Student 2 ID</label>
                <input type="text" class="form-control" id="studentId2" name="studentId2" placeholder="Enter Student 2 ID">
            </div>
        </div>
        <button type="button" class="btn btn-primary" id="compareBtn">Compare Students</button>
    </form>
    <div class="mt-4" id="studentInfo">
        <h2>Student Information</h2>
        <p><strong>Student ID:</strong> <span id="studentId"></span></p>
        <p><strong>Student NAME:</strong> <span id="studentName"></span></p>
        <p><strong>Semester:</strong> <span id="SemesterLabel"></span></p>
        <p><strong>CGPA:</strong> <span id="studentCgpa"></span></p>
    </div>
</div>

<!-- Include jQuery library -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<!-- Include Bootstrap JS -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

<!-- AJAX call to the RESTful API endpoint -->
<script>
    $(document).ready(function() {
        $("#compareBtn").click(function() {
            var studentId1 = $("#studentId1").val();
            var studentId2 = $("#studentId2").val();
            $.ajax({
                url: "http://localhost:8080/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/api/Stateless/student/compareCgpa", // replace with your actual API endpoint
                type: "GET",
                data: {
                    studentId1: studentId1,
                    studentId2: studentId2
                },
                success: function(response) {
                    // Update student information on success
                    $("#studentName").text(response.name);
                    $("#studentId").text(response.studentId);
                    $("#SemesterLabel").text(response.semester);
                    $("#studentCgpa").text(response.cgpa);
                },
                error: function(xhr, status, error) {
                    // Handle error
                    console.log("Error: " + error);
                }
            });
        });
    });
</script>
</body>
</html>
