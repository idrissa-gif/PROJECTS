<?php
include("connection.php");
include("function.php");

if (array_key_exists('submit', $_POST)) {
    $FullName = $_POST['FullName'];
    $email = $_POST["email"];
    $Phone = $_POST["Phone"];
    $adults = $_POST['adults'];
    $children = $_POST['children'];
    $destination = $_POST['destination'];
    $date = $_POST['book_date'];
    // echo $FullName . ' ' . $email . ' ' . $Phone . ' ' . $adults . ' ' . $children . ' ' . $destination . ' ' . $date;

    $query = "INSERT INTO `BookTable`(`destination`, `start_date`, `FullName`, `email`, `Phone`, `adults`, `children`) VALUES ('$destination','$date','$FullName','$email','$Phone','$adults','$children')";
    if (!$con->query($query)) {
        echo ("Error description: " . $con->error);
    }

    echo "<script> alert('You have got a Free Quote')
        window.location.replace('SouthAfricaTours.html'); </script>";
} else {
    echo "<script> alert('Failed to get a Free Quote')
        window.location.replace('SouthAfricaTours.html'); </script>";
}

?>
<html lang="en"><head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta http-equiv="x-ua-compatible" content="ie=edge">
  <title>Book a Trip</title>
  <!-- MDB icon -->
  <link rel="icon" href="img/mdb-favicon.ico" type="image/x-icon">
  <!-- Font Awesome -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
  <!-- Google Fonts Roboto -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700;900&amp;display=swap">
  <!-- MDB -->
  <link rel="stylesheet" href="./css/mdb.min.css">
  <!-- customize  -->
  <link rel="stylesheet" href="./css/sign_up.css">
  <style>
    body {

      background: url(./images/Book_backgroundimg.png);
      background-repeat: no-repeat;
      background-size: 100% 150vh;
    }

    .navbar-brand,
    .nav-link {
      color: black;
    }

    .text-center,
    form {
      color: white;
    }

    .container-fluid {
      background-color: #FCD19C;
    }

    .navbar {
      position: -webkit-sticky;
      position: sticky;
      top: 0;
      z-index: 2;
    }

    .login-signup {
      padding-top: 5%;
      margin: 0% 20%;

    }
  </style>

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>

<style>INPUT:-webkit-autofill,SELECT:-webkit-autofill,TEXTAREA:-webkit-autofill{animation-name:onautofillstart}INPUT:not(:-webkit-autofill),SELECT:not(:-webkit-autofill),TEXTAREA:not(:-webkit-autofill){animation-name:onautofillcancel}@keyframes onautofillstart{}@keyframes onautofillcancel{}</style></head>

<body>
  <!-- header section start -->
  <nav class="navbar navbar-expand-lg bg-light">
    <div class="container-fluid">
      <a class="navbar-brand" href="./home.html">TONGA</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarSupportedContent">
        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="home.html">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="destinations.html">Destinations</a>
          </li>
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="book.html">Booking</a>
          </li>
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="contact_us.html">Contact us</a>
          </li>
        </ul>
      </div>
    </div>
  </nav>
  <!-- header section end -->
  <div>
    <!-- Start your project here-->
    <div class="login-signup">

      <div class="tab-content">
        <div class="tab-pane fade show active" id="pills-login" role="tabpanel" aria-labelledby="tab-login">
          <form method="POST" action="./booking.php" id="login">

            <!-- destionation input -->
            <div class="form-outline mb-4" metho="">
              <input type="text" id="destination" class="form-control" name="destination" style="background-color: white; color:black" required="">
              <label class="form-label" for="destination" style="margin-left: 0px;">Destination</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 72px;"></div><div class="form-notch-trailing"></div></div></div>

            <!-- FullName input -->
            <div class="form-outline mb-4" metho="">
              <input type="text" id="loginName" class="form-control" name="FullName" style="background-color: white; color:black" required="">
              <label class="form-label" for="loginName" style="margin-left: 0px;">FullName</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 62.4px;"></div><div class="form-notch-trailing"></div></div></div>

            <!-- Email input -->
            <div class="form-outline mb-4" metho="">
              <input type="email" id="email" class="form-control" name="email" style="background-color: white; color:black" required="">
              <label class="form-label" for="email" style="margin-left: 0px;">Email</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 40px;"></div><div class="form-notch-trailing"></div></div></div>

            <!-- Phone input -->
            <div class="form-outline mb-4" metho="">
              <input type="text" id="Phone" class="form-control" name="Phone" style="background-color: white; color:black" required="">
              <label class="form-label" for="Phone" style="margin-left: 0px;">Phone</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 44.8px;"></div><div class="form-notch-trailing"></div></div></div>

            <!-- Adults input -->
            <div class="form-outline mb-4" metho="">
              <input type="number" id="adults" class="form-control" name="adults" style="background-color: white; color:black" required="">
              <label class="form-label" for="adults" style="margin-left: 0px;">Adults</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 43.2px;"></div><div class="form-notch-trailing"></div></div></div>

            <!-- Children input -->
            <div class="form-outline mb-4" metho="">
              <input type="number" id="children" class="form-control" name="children" style="background-color: white; color:black" required="">
              <label class="form-label" for="children" style="margin-left: 0px;">Children</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 56px;"></div><div class="form-notch-trailing"></div></div></div>
             <!-- Start date input -->
             <div class="form-outline mb-4" style="background-color: white;" metho="">
              <input id="datetime" type="date" class="form-control" name="book_date" style="background-color: white; color: black; opacity: 0;" required="">
              <label class="form-label" for="date" style="margin-left: 0px;">Start date</label>
            <div class="form-notch"><div class="form-notch-leading" style="width: 9px;"></div><div class="form-notch-middle" style="width: 65.6px;"></div><div class="form-notch-trailing"></div></div></div>
            
            
            <!-- Quote Message -->
            <div class="mb-3">
              <textarea class="form-control" id="message" rows="8" colums="4" name="message" tabindex="4" placeholder="Write your message"></textarea>
            </div>

            <!-- Submit button -->
            <button type="submit" class="btn btn-primary btn-block mb-4" name="submit" style="background-color: green;">Book Trip</button>

            <!-- Register buttons -->
            <div class="text-center">
              <p style="color: white;">Not a member? <a href="register.html">Register</a></p>
            </div>
          </form>
        </div>

      </div>
      <!-- Pills content -->
      <!-- End your project here-->
    </div>



    <!-- MDB -->
    <script type="text/javascript" src="js/mdb.min.js"></script>
    <!-- Custom scripts -->
    <script type="text/javascript"></script>
    <script>
      document.getElementById('destination').value=sessionStorage.getItem('destination');
    </script>



</div></body></html>t