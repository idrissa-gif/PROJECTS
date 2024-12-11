<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <title>Reviews</title>
    <!-- Include Bootstrap CSS -->
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
    <!-- Include FontAwesome CSS for stars icons -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css">
    <style>
        /* Add custom CSS for highlighting selected rows */
        .selected {
            background-color: #e6f2ff;
        }

        /* Add custom CSS for changing the color of stars to yellow */
        .fa-star{
            color: #d0d000;
        }
        .selected i.fa-star {
            color: #5e83ea;
        }
    </style>
</head>
<body>
<div style="margin-bottom: 5%;">
    <jsp:include page="includes/sidebar.jsp"/>
</div>
<div class="container mt-5">
    <h1>Reviews</h1>
    <table class="table mt-4">
        <thead>
        <tr>
            <th>ID</th>
            <th>Reviewer Name</th>
            <th>Message</th>
            <th>Target</th>
            <th>Rate</th>
        </tr>
        </thead>
        <tbody>
        <!-- Loop through reviews and display them in rows -->
        <c:forEach items="${reviews}" var="review">
            <tr class="review-row">
                <td>${review.id}</td>
                <td>${review.reviewer_name}</td>
                <td>${review.message}</td>
                <td>${review.target}</td>
                <td>
                    <!-- Display rate as stars using FontAwesome icons -->
                    <c:set var="starIcon" value="fas fa-star" />
                    <c:forEach begin="1" end="${review.rate}">
                        <i class="${starIcon}"></i>
                    </c:forEach>
                </td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>

<!-- Include jQuery for handling mouse events -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script>
    // Add event listener for click event on table rows
    $('.review-row').on('click', function() {
        // Toggle the 'selected' class on the clicked row
        $(this).toggleClass('selected');
    });
</script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.min.js" integrity="sha384-cuYeSxntonz0PPNlHhBs68uyIAVpIIOZZ5JqeqvYYIcEL727kskC66kF92t6Xl2V" crossorigin="anonymous"></script>

</body>
</html>
