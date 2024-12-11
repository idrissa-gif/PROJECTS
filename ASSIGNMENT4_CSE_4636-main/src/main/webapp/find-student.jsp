<!DOCTYPE html>
<html>
<head>
    <title>Find Student</title>
    <!-- Include Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body>
<div >
    <jsp:include page="options.jsp"/>
</div>
<div class="container mt-5">
    <h1 class="mb-4">Find Student</h1>
    <form id="findStudentForm">
        <div class="form-group">
            <label for="studentId">Student ID:</label>
            <input type="text" name="studentId" id="studentId" class="form-control">
        </div>
        <input type="submit" value="Find" class="btn btn-primary">
    </form>

    <hr>

    <h2>Student Details</h2>
    <p id="studentIdLabel"></p>
    <p id="studentNameLabel"></p>
    <p id="SemesterLabel"></p>
    <p id="CgpaLabel"></p>
</div>

<script>
    // Add JavaScript code to handle form submission
    $("#findStudentForm").submit(function(event) {
        event.preventDefault();
        var studentId = $("#studentId").val();
        // Make an API request to retrieve student data
        $.get("/CSE4636_ASSIGNMENT4-1.0-SNAPSHOT/api/Stateless/student/find/"+studentId)
            .done(function(data) {
                // Display student data in the HTML output
                $("#studentIdLabel").text("Student ID: " + data.studentId);
                $("#studentNameLabel").text("Student Name: " + data.name);
                $("#SemesterLabel").text("Semester: " + data.semester);
                $("#CgpaLabel").text("Cgpa: " + data.cgpa);

            })
            .fail(function() {
                // Handle error
                alert("Failed to retrieve student data.");
            });
    });
</script>
</body>
</html>
