<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
    <title>Country List</title>
    <!-- Include Bootstrap CSS -->
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div style="margin-bottom: 5%;">
    <jsp:include page="../includes/sidebar.jsp"/>
</div>
<div class="container mt-5">
    <h1>Country List</h1>
    <table class="table mt-3">
        <thead>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Tours</th>
            <th>Operators</th>
            <th>Image</th>
            <th></th>
            <th></th>
        </tr>
        </thead>
        <tbody>
        <%-- Loop through the list of countries and generate table rows dynamically --%>
        <c:forEach items="${countries}" var="country">
            <tr>
                <td>${country.id}</td>
                <td>${country.name}</td>
                <td>${country.tours}</td>
                <td>${country.operators}</td>
                <td><img src="/images/${country.image}" alt="${country.name} Image" style="max-width: 100px; max-height: 100px;"></td>
                <td><a href="/editCountry/${country.id}" class="btn btn-primary">Edit</a></td>
                <td><a href="/deleteCountry/${country.id}" class="btn btn-danger">Delete</a></td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js" integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V" crossorigin="anonymous"></script>

</body>

</html>
