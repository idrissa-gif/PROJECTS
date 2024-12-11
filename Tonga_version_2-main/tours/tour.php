<head>
  <link rel="stylesheet" href="../css/tour.css">
</head>
<?php
include("../connection.php");
include("../headerAndFooter/header.php");
$query = "SELECT `tour_name`, `tour_operator`, `country`, `price`, `image`, `operator_image`, `reviews`, `description` FROM `Tours`";
$result = mysqli_query($con, $query); ?>

<!-- <div class='FeaturedPlaces'> -->
<div class="row">
  <?php

  while ($row = mysqli_fetch_array($result)) {

    echo "

    <div class='card col-sm-6'>

    <img class='card-img-top' src='{$row['image']}'>
  
    <div class='card-body'>
  
      <h4 class='card-tour-title'>{$row['tour_name']}</h4>
      <h5 class='card-price'>{$row['price']}</h5>
      <h5 class='card-title'>{$row['country']}: <text class='no-bold'>{$row['country']}</text></h5>
      <p class='card-text'>{$row['description']}</p>
      <h5 class='card-title'>You visit: <text class='no-bold'>{$row['reviews']}</text></h5>
      <h5 class='card-title'>Reviews: <text class='no-bold'>{$row['reviews']}</text></h5>      

      <a href='krugerpark.html' class='btn btn-primary'>Explore</a>
    </div>
  
    <div class='card-footerg'>
      <p>Offered By<p>
      <img class='logo' src='{$row['operator_image']}'>
      <small class='text-muted'>{$row['tour_operator']}</small>
    </div>
      
</div>
    ";
  }

  ?>

</div>
<!-- </div> -->
<?php
include("../headerAndFooter/footer.php");
