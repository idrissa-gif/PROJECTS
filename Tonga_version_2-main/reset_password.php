

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta http-equiv="x-ua-compatible" content="ie=edge" />
    <title>Change password</title>
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
    <link rel="stylesheet" href="./css/mdb.min.css"/>
    <!-- customize  -->
    <link rel="stylesheet" href="./css/sign_up.css">
    <style>
      html,body { height: 100%; }
      body{
        background: url(./images/resetpasswordimg.jpeg);
        background-repeat: no-repeat; 
        background-size: 100% 100vh; 
      	display: -ms-flexbox;
      	display: -webkit-box;
      	display: flex;
      	-ms-flex-align: center;
      	-ms-flex-pack: center;
      	-webkit-box-align: center;
      	align-items: center;
      	-webkit-box-pack: center;
      	justify-content: center;
      	background-color: #f5f5f5;
      }   
      
      form{
      	padding-top: 10px;
      	font-size: 13px;
      	margin-top: 30px;
      }
      
      .card-title{ font-weight:300; }
      
      .btn{
      	font-size: 13px;
      }
      
      .login-form{ 
      	width:320px;
      	margin:20px;
      }
      
      .sign-up{
      	text-align:center;
      	padding:20px 0 0;
      }
      
      span{
      	font-size:14px;
      }
      
      .submit-btn{
      	margin-top:20px;
      }
    </style>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>

</head>

<body>
  <div class="card login-form">
    <div class="card-body">
      <h3 class="card-title text-center">Change password</h3>
      
      <!--Password must contain one lowercase letter, one number, and be at least 7 characters long.-->
      
      <div class="card-text">
        <form action="./resetpassword.php" method="POST">
          
          <div class="alert alert-danger alert-dismissible fade show" role="alert">
            <strong>Holy guacamole!</strong> You should check in on some of those fields below.
            <a class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </a>
          </div>
          <div class="form-group">
            <input type="hidden" name="updated_token" value="<?php if(isset($_GET['token'])) {echo $_GET['token'];} ?>">
          </div>
          <div class="form-group">
            <label for="exampleInputEmail1">Email Address</label>
            <input type="email" class="form-control form-control-sm" name = "email" value = "<?php if(isset($_GET['email'])){echo $_GET['email'];} ?>" required>
          </div>
          <div class="form-group">
            <label for="exampleInputEmail1">Your new password</label>
            <input type="password" class="form-control form-control-sm" name="new_password" required>
          </div>
          <div class="form-group">
            <label for="exampleInputEmail1">Repeat password</label>
            <input type="password" class="form-control form-control-sm" name="conform_new_password" required>
          </div>
          <button type="submit" class="btn btn-primary btn-block submit-btn" id="submit" name="submit">Confirm</button>
        </form>
      </div>
    </div>
  </div>  
  <!-- MDB -->
  <script type="text/javascript" src="js/mdb.min.js"></script>
  <!-- Custom scripts -->
  <script type="text/javascript"></script>

  </body>
</html>
