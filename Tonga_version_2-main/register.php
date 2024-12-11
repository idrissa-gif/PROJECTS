<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <title>Registion</title>
    <!-- MDB icon -->
    <link rel="icon" href="img/mdb-favicon.ico" type="image/x-icon" />
    <!-- Font Awesome -->
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css"
    />
    <!-- Google Fonts Roboto -->
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700;900&display=swap"
    />
    <!-- MDB -->
    <link rel="stylesheet" href="../css/mdb.min.css" />
    <!-- customize  -->
    <link rel="stylesheet" href="../css/sign_up.css">

    <style>
      body{
        background: url(../image/login_backgroundimag.png);
        background-repeat: no-repeat; 
        background-size: 100% 100vh;   
      }
      .navbar-brand, .nav-link
      {
        color: black;
      }
      .text-center,form
      {
        color:white;
      }

      .container-fluid
      {
        background-color: #FCD19C;
      }
      .navbar{
        position: -webkit-sticky; 
        position: sticky; 
        top: 0;
        padding: 5px; 
        z-index: 2;
      }
      .login-signup
      {
        padding-top: 2%;
        margin: 0% 20%;
      }

    </style>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>

</head>

<body>
  
    <!-- header section start -->
    <nav class="navbar navbar-expand-lg bg-light" >
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
    
    <!-- Start your project here-->
    <div id="register">
        <div class="login-signup">
          <!-- Pills navs -->
        <ul class="nav nav-pills nav-justified mb-3" id="ex1" role="tablist">
          <li class="nav-item" role="presentation">
          <a class="nav-link" id="tab-login" href="login.php">Login</a>
        </li>
        <li class="nav-item" role="presentation">
          <a class="nav-link active" id="tab-register" data-mdb-toggle="pill" href="#pills-register" role="tab"
            aria-controls="pills-register" aria-selected="true">Register</a>
        </li>
      </ul>
      <!-- Pills navs -->

      <!-- Pills content -->
      <div class="tab-content">
        <div class="" id="pills-register" role="tabpanel" aria-labelledby="tab-register">
          <form method="POST" action="sign.php" id="register" name="register" enctype="application/x-www-form-urlencoded">
            <div class="text-center mb-3">
              <p>Sign up with:</p>
              <button type="button" class="btn btn-link btn-floating mx-1"style="color: blue">
                <i class="fab fa-facebook-f"></i>
              </button>

              <button type="button" class="btn btn-link btn-floating mx-1" >
                <i class="fab fa-google"></i>
              </button>

              <button type="button" class="btn btn-link btn-floating mx-1" >
                <i class="fab fa-twitter"></i>
              </button>

              <button type="button" class="btn btn-link btn-floating mx-1" >
                <i class="fab fa-github"></i>
              </button>
            </div>

            <p class="text-center">or:</p>

            <!-- Name input -->
            <div class="form-outline mb-4">
              <input type="text" id="registerName" class="form-control" name="r_name" style="background-color: white; color:black"/>
              <label class="form-label" for="registerName">Name</label>
            </div>

            <!-- Username input -->
            <div class="form-outline mb-4">
              <input type="text" id="registerUsername" class="form-control" name="r_username" style="background-color: white; color:black"/>
              <label class="form-label" for="registerUsername">Username</label>
            </div>

            <!-- Email input -->
            <div class="form-outline mb-4">
              <input type="email" id="registerEmail" class="form-control" name="r_email" style="background-color: white; color:black" required/>
              <label class="form-label" for="registerEmail">Email</label>
            </div> 

            <!-- Phone input -->
            <div class="form-outline mb-4">
              <input type="number" id="registerPhone" class="form-control" name="r_phone" style="background-color: white; color:black"/>
              <label class="form-label" for="registerEmail">Phone number</label>
            </div>

            <!-- Password input -->
            <div class="form-outline mb-4">
              <input type="password" id="registerPassword" class="form-control" name="r_password" required style="background-color: white; color:black"/>
              <label class="form-label" for="registerPassword">Password</label>
            </div>

            <!-- Repeat Password input -->
            <div class="form-outline mb-4">
              <input type="password" id="registerRepeatPassword" class="form-control" name = "r_conform_password" style="background-color: white; color:black"/>
              <label class="form-label" for="registerRepeatPassword">Repeat password</label>
            </div>

            <!-- Checkbox -->
            <div class="form-check d-flex justify-content-center mb-4">
              <input class="form-check-input me-2" type="checkbox" value="" id="registerCheck" checked
                aria-describedby="registerCheckHelpText" style="background-color: white; color:black"/>
              <label class="form  -check-label" for="registerCheck">
                I have read and agree to the terms
              </label>
            </div>

            <!-- Submit button -->
            <button type="submit" class="btn btn-primary btn-block mb-3" name="r_submit" id="r_submit">Sign in</button>
          </form>
        </div>
      </div>
    </div>

  <!-- Pills content -->
  </div>
    
    <!-- End your project here-->
    <!-- MDB -->
    <script type="text/javascript" src="js/mdb.min.js"></script>
    <!-- Custom scripts -->
    <script type="text/javascript"></script>

  </body>
</html>
