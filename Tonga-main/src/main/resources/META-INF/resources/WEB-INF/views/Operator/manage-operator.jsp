<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
    <title>Add Operator</title>
    <!-- Include Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <!-- Include custom CSS for highlighting selected operator -->
    <style>
        .highlight {
            background-color: #f8d7da;
        }
    </style>
</head>
<body>
<div style="margin-bottom: 5%;">
    <jsp:include page="../includes/sidebar.jsp"/>
</div>
<div class="container mt-5">
    <h1 class="text-center mb-4">Operators</h1>
    <form action="/saveOperator" method="post" enctype="multipart/form-data">
        <!-- Add your form fields here -->
    </form>

    <table class="table table-striped mt-3">
        <thead>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Tours</th>
            <th>Countries</th>
            <th>Rate</th>
            <th>Image</th>
            <th>Actions</th>
        </tr>
        </thead>
        <tbody>
        <c:forEach var="operator" items="${operators}">
            <tr class="${selectedOperatorId == operator.id ? 'highlight' : ''}">
                <td>${operator.id}</td>
                <td>${operator.name}</td>
                <td>${operator.tours}</td>
                <td>${operator.countries}</td>
                <td>${operator.rate}</td>
                <td><img src="/images/${operator.image}" alt="${operator.name} Image" style="max-width: 100px; max-height: 100px;" \></td>
                <td>
                    <a href="/editOperator?id=${operator.id}" class="btn btn-primary">Edit</a>
                    <a href="/deleteOperator?id=${operator.id}" class="btn btn-danger">Delete</a>
                </td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>
<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js" integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.0.7/dist/umd/popper.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
