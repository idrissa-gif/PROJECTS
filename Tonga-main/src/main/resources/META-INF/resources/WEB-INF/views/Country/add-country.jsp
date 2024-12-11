<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <title>Add Country</title>
    <!-- Include Bootstrap CSS -->
    <link href="../../../../../css/style.css" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>
<body>
<div style="margin-bottom: 5%;">
    <jsp:include page="../includes/sidebar.jsp"/>
</div>
<div class="container mt-5">
    <h1 class="mb-4" style="text-align: center">Add Country</h1>
    <h3 style="text-align: center"><strong>${message}</strong></h3>
    <form action="addCountry" method="get">
        <div class="form-group">
            <label for="name">Country Name:</label>
            <input type="text" class="form-control" id="name" name="name" required>
        </div>
        <div class="form-group">
            <label for="tours">Number of Tours:</label>
            <input type="number" class="form-control" id="tours" name="tours" required>
        </div>
        <div class="form-group">
            <label for="operators">Number of Operators:</label>
            <input type="number" class="form-control" id="operators" name="operators" required>
        </div>
        <div class="form-group">
            <label for="image">Image:</label>
            <input type="file" class="form-control" id="image" name="image" required>
        </div>
        <button type="submit" class="btn btn-primary">Add Country</button>
    </form>
</div>

<!-- Include Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js" integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.0.7/dist/umd/popper.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
