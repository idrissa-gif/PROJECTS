<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Tours List</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <style>
        .tour-card:hover {
            background-color: #f8f9fa;
            cursor: pointer;
        }
        .selected-tour {
            background-color: #007bff;
            color: #fff;
        }
    </style>
</head>
<body>

<div style="margin-bottom: 5%;">
    <jsp:include page="../includes/sidebar.jsp"/>
</div>

<div class="container mt-5">
    <h1 class="text-center">Tours List</h1>
    <table class="table table-hover mt-3">
        <thead>
        <tr>
            <th scope="col">#</th>
            <th scope="col">Tour Name</th>
            <th scope="col">Tour Operator</th>
            <th scope="col">Countries</th>
            <th scope="col">Prices</th>
            <th scope="col">Number of Persons</th>
            <th scope="col">Rate</th>
            <th scope="col">Image1</th>
            <th scope="col">Image2</th>
            <th scope="col">Image3</th>
            <th scope="col">Actions</th>
        </tr>
        </thead>
        <tbody>
        <c:forEach items="${tours}" var="tour" varStatus="status">
            <tr class="tour-card" data-tour-id="${tour.id}">
                <th scope="row">${status.index + 1}</th>
                <td>${tour.tour_name}</td>
                <td>${tour.tour_operator}</td>
                <td>${tour.countries}</td>
                <td>${tour.prices}</td>
                <td>${tour.number_person}</td>
                <td>${tour.rate}</td>
                <td><img src="/images/${tour.image1}" alt="${tour.tour_name} Image" style="max-width: 100px; max-height: 100px;"></td>
                <td><img src="/images/${tour.image2}" alt="${tour.tour_name} Image" style="max-width: 100px; max-height: 100px;"></td>
                <td><img src="/images/${tour.image3}" alt="${tour.tour_name} Image" style="max-width: 100px; max-height: 100px;"></td>
                <td>
                    <a href="/editTour?tour_id=${tour.id}" class="btn btn-sm btn-primary">Edit</a>
                    <a href="/deleteTour?tour_id=${tour.id}" class="btn btn-sm btn-danger">Delete</a>
                </td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>

<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.3/dist/umd/popper.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
<script>
    $(document).ready(function() {
        $(".tour-card").click(function() {
            $(this).toggleClass("selected-tour");
        });
    });
</script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js" integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V" crossorigin="anonymous"></script>


</body>
</html>
