<%@ taglib prefix="th" uri="http://www.springframework.org/tags/form" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>
<body>
<nav class="navbar bg-success fixed-top">
    <div class="container-fluid">
        <button class="navbar-toggler" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasNavbar" aria-controls="offcanvasNavbar">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="offcanvas offcanvas-end" tabindex="-1" id="offcanvasNavbar" aria-labelledby="offcanvasNavbarLabel">
            <div class="offcanvas-header">
                <h5 class="offcanvas-title" id="offcanvasNavbarLabel">Tonga</h5>
                <button type="button" class="btn-close" data-bs-dismiss="offcanvas" aria-label="Close"></button>
            </div>
            <div class="offcanvas-body">
                <ul class="navbar-nav justify-content-end flex-grow-1 pe-3">
                    <li class="nav-item">
                        <a class="nav-link" aria-current="page" href="/dashboard">Dashboard</a>
                    </li>
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Tour
                        </a>
                        <ul class="dropdown-menu">
                            <li><a class="dropdown-item" href="/showaddform">Add</a></li>
                            <li><a class="dropdown-item" href="/manage-tour">Manage</a></li>
                        </ul>
                    </li>
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Operator
                        </a>
                        <ul class="dropdown-menu">
                            <li><a class="dropdown-item" href="/addOperator">Add</a></li>
                            <li><a class="dropdown-item" href="/manage-operator">Manage</a></li>
                        </ul>
                    </li>
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Country
                        </a>
                        <ul class="dropdown-menu">
                            <li><a class="dropdown-item" href="/add-country">Add</a></li>
                            <li><a class="dropdown-item" href="/manage-country">Manage</a></li>
                        </ul>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" aria-current="page" href="/reviews">Review</a>
                    </li>
                    <li class="nav-item">
                        <a class="btn btn-primary" aria-current="page" href="#">Log Out</a>
                    </li>
                </ul>
            </div>
        </div>
    </div>
</nav>
</body>