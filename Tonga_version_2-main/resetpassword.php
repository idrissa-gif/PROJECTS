<?php

include("connection.php");
include("function.php");
echo "<script>alert('hello1')</script>";
echo "<script>alert('hello2')</script>";
if(array_key_exists('submit',$_POST))
{
    echo "<script>alert('hello3')</script>";
    $email = mysqli_real_escape_string($con,$_POST['email']);
    $new_password = mysqli_real_escape_string($con,$_POST['new_password']);
    $conform_new_password = mysqli_real_escape_string($con,$_POST['conform_new_password']);
    $updated_token = mysqli_real_escape_string($con,$_POST['updated_token']);
    echo "<script>alert('$email')</script>";
    echo "<script>alert('$new_password')</script>";
    echo "<script>alert('$conform_new_password')</script>";
    echo "<script>alert('$updated_token')</script>";
    
}
?>