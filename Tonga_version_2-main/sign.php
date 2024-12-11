<?php
session_start();
include("connection.php");
include("function.php");

if(array_key_exists('r_submit',$_POST))
{
    $user_name = $_POST['r_name'] .' '. $_POST['r_username'];
    $email = $_POST["r_email"];
    $phone = $_POST["r_phone"];
    $password =$_POST['r_password'];
    $conform_password =$_POST['r_conform_password'];
    if(!empty($user_name))
    {
      $duplication = mysqli_query($con,"SELECT * FROM users WHERE user_name = '$user_name' OR email = '$email'");
      if(mysqli_num_rows($duplication) > 0)
      {
        echo "<script> alert('Username or Email has been already taken')
        window.location.replace('register.html'); </script>";
      }
      else 
      {
        if($password == $conform_password)
        {
          $token = md5(rand());
          $query ="INSERT INTO users(user_name , email , phone , password,verified_token) VALUES('$user_name','$email','$phone','$password','$token')";
          mysqli_query($con,$query);
          echo "<script> 
          alert('Registration Successfully')
          window.location.replace('login.html'); </script>";
        }
        else 
        {
          echo "<script> alert('Passwords does not Match')
          window.location.replace('register.html'); </script>";
        }
      }
      

    }
    else {
      echo "<script> alert('Passwords does not Match')
      window.location.replace('register.html'); </script>";
    }
    
}else if(array_key_exists('submit',$_POST))
{
    if($_SERVER['REQUEST_METHOD']=='POST')
    {
        $email = $_POST['email'];
        $query = "SELECT * from users where '$email' = users.email";
        $result=mysqli_query($con,$query);
        if(mysqli_num_rows($result) == 1)
        {
          echo "<script> alert('Successfully connected')
          window.location.replace('home.html'); </script>";
        }
        else
        {
          echo "<script> alert('Failed: Email or Password is Invalid')
          window.location.replace('login.html'); </script>";
        }
    }
}
?>