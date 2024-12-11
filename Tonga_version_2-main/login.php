

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <title>Login</title>
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
    <link rel="stylesheet" href="../css/mdb.min.css"/>
    <!-- customize  -->
    <link rel="stylesheet" href="../css/sign_up.css">
    <style>
      body{
        background: url(../image/signin_background.png);
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
    <!-- Pills navs -->
    <ul class="nav nav-pills nav-justified mb-3" id="ex1" role="tablist">
    <li class="nav-item" role="presentation">
      <a class="nav-link active" id="tab-login" data-mdb-toggle="pill" href="#pills-login" role="tab"
        aria-controls="pills-login" aria-selected="true">Login</a>
    </li>
    <li class="nav-item" role="presentation">
      <a class="nav-link" id="tab-register" href="register.php" >Register</a>
    </li>
    </ul>
    <!-- Pills navs -->

    <!-- Pills content -->
    <div class="tab-content">
    <div class="tab-pane fade show active" id="pills-login" role="tabpanel" aria-labelledby="tab-login">
      <form method="POST" action="sign.php" id="login">
        <div class="text-center mb-3">
          <p style="color: white;">Sign in with:</p>
          <button type="button" class="btn btn-link btn-floating mx-1">
            <i class="fab fa-facebook-f"></i>
          </button>
        
          <button type="button" class="btn btn-link btn-floating mx-1">
            <i class="fab fa-google"></i>
          </button>
        
          <button type="button" class="btn btn-link btn-floating mx-1">
            <i class="fab fa-twitter"></i>
          </button>
        
          <button type="button" class="btn btn-link btn-floating mx-1">
            <i class="fab fa-github"></i>
          </button>
        </div>
      
        <p class="text-center" style="color: white;">or:</p>
      
        <!-- Email input -->
        <div class="form-outline mb-4" metho>
          <input type="email" id="loginName" class="form-control" name = "email" style="background-color: white; color:black"/>
          <label class="form-label" for="loginName">Email</label>
        </div>
      
        <!-- Password input -->
        <div class="form-outline mb-4">
          <input type="password" id="loginPassword" class="form-control" name = "password" style="background-color: white; color:black"/>
          <label class="form-label" for="loginPassword">Password</label>
        </div>
      
        <!-- 2 column grid layout -->
        <div class="row mb-4">
          <div class="col-md-6 d-flex justify-content-center">
            <!-- Checkbox -->
            <div class="form-check mb-3 mb-md-0">
              <input class="form-check-input" type="checkbox" value="" id="loginCheck" checked style="background-color: white; color:black"/>
              <label class="form-check-label" for="loginCheck" style="color: white;"> Remember me </label>
            </div>
          </div>
        
          <div class="col-md-6 d-flex justify-content-center">
            <!-- Simple link -->
            <a href="forgetPassword.html">Forgot password?</a>
          </div>
        </div>
      
        <!-- Submit button -->
        <button type="submit" class="btn btn-primary btn-block mb-4" name="submit">Sign in</button>
      
        <!-- Register buttons -->
        <div class="text-center">
          <p style="color: white;">Not a member? <a href="register.php">Register</a></p>
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

  </body>
</html>
