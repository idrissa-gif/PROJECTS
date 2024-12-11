<?php
session_start();
error_reporting(0);
include('includes/dbconnection.php');
if (strlen($_SESSION['ofsmsaid'] == 0)) {
  header('location:logout.php');
} else {



?>
  <!doctype html>
  <html class="no-js" lang="en">

  <head>

    <title>Tonga Management System | Dashboard</title>

    <link href="https://fonts.googleapis.com/css?family=Play:400,700" rel="stylesheet">
    <!-- Bootstrap CSS
		============================================ -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <!-- Bootstrap CSS
		============================================ -->
    <link rel="stylesheet" href="css/font-awesome.min.css">
    <!-- owl.carousel CSS
		============================================ -->
    <link rel="stylesheet" href="css/owl.carousel.css">
    <link rel="stylesheet" href="css/owl.theme.css">
    <link rel="stylesheet" href="css/owl.transitions.css">
    <!-- animate CSS
		============================================ -->
    <link rel="stylesheet" href="css/animate.css">
    <!-- normalize CSS
		============================================ -->
    <link rel="stylesheet" href="css/normalize.css">
    <!-- meanmenu icon CSS
		============================================ -->
    <link rel="stylesheet" href="css/meanmenu.min.css">
    <!-- main CSS
		============================================ -->
    <link rel="stylesheet" href="css/main.css">
    <!-- morrisjs CSS
		============================================ -->
    <link rel="stylesheet" href="css/morrisjs/morris.css">
    <!-- mCustomScrollbar CSS
		============================================ -->
    <link rel="stylesheet" href="css/scrollbar/jquery.mCustomScrollbar.min.css">
    <!-- metisMenu CSS
		============================================ -->
    <link rel="stylesheet" href="css/metisMenu/metisMenu.min.css">
    <link rel="stylesheet" href="css/metisMenu/metisMenu-vertical.css">
    <!-- calendar CSS
		============================================ -->
    <link rel="stylesheet" href="css/calendar/fullcalendar.min.css">
    <link rel="stylesheet" href="css/calendar/fullcalendar.print.min.css">
    <!-- style CSS
		============================================ -->
    <link rel="stylesheet" href="style.css">
    <!-- responsive CSS
		============================================ -->
    <link rel="stylesheet" href="css/responsive.css">
    <!-- modernizr JS
		============================================ -->
    <script src="js/vendor/modernizr-2.8.3.min.js"></script>
  </head>

  <body>
    <?php include_once('includes/sidebar.php'); ?>


    <!-- Start Welcome area -->
    <div class="all-content-wrapper">

      <div>
        <div>
          <?php include_once('includes/header.php'); ?>


        </div>

        <div class="product-sales-area mg-tb-30">
          <div class="container-fluid">
            <div class="row" style="margin-left: 150px;">

              <div class="col-lg-3 col-md-3 col-sm-3 col-xs-12">
                <div class="white-box analytics-info-cs mg-b-10 res-mg-t-30">
                  <?php
                  $sql1 = "SELECT * from  tblorder where Status is null ";
                  $query1 = $dbh->prepare($sql1);
                  $query1->execute();
                  $results1 = $query1->fetchAll(PDO::FETCH_OBJ);
                  $totneworder = $query1->rowCount();
                  ?>
                  <h3 class="box-title">Total Tours</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-globe" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totneworder); ?>)</span></li>
                    <a href="new-order.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>


                <div class="white-box analytics-info-cs">
                  <?php
                  $sql2 = "SELECT * from  tblorder";
                  $query2 = $dbh->prepare($sql2);
                  $query2->execute();
                  $results2 = $query2->fetchAll(PDO::FETCH_OBJ);
                  $totorder = $query2->rowCount();
                  ?>
                  <h3 class="box-title">Total Reviews</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-comments-o" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totorder); ?>)</span></li>
                    <a href="cancelled-order.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>

              </div>
              <div class="col-lg-3 col-md-3 col-sm-3 col-xs-12">
                <div class="white-box analytics-info-cs mg-b-10">
                  <?php
                  $sql3 = "SELECT * from  tblorder where Status='Confirmed'";
                  $query3 = $dbh->prepare($sql3);
                  $query3->execute();
                  $results3 = $query3->fetchAll(PDO::FETCH_OBJ);
                  $totconorder = $query3->rowCount();
                  ?>
                  <h3 class="box-title">Total Tour Operators</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-globe" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totconorder); ?>)</span></li>
                    <a href="confirmed-order.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>

                <div class="white-box analytics-info-cs">
                  <?php
                  $sql4 = "SELECT * from  tblproducts";
                  $query4 = $dbh->prepare($sql4);
                  $query4->execute();
                  $results4 = $query4->fetchAll(PDO::FETCH_OBJ);
                  $totproduct = $query4->rowCount();
                  ?>
                  <h3 class="box-title">Total Books</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-globe" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totproduct); ?>)</span></li>
                    <a href="manage-products.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>

                
              </div>

              <div class="col-lg-3 col-md-3 col-sm-3 col-xs-12">
                <div class="white-box analytics-info-cs mg-b-10">
                  <?php
                  $sql3 = "SELECT * from  tblorder where Status='Confirmed'";
                  $query3 = $dbh->prepare($sql3);
                  $query3->execute();
                  $results3 = $query3->fetchAll(PDO::FETCH_OBJ);
                  $totconorder = $query3->rowCount();
                  ?>
                  <h3 class="box-title">Total Tour Operators</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-globe" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totconorder); ?>)</span></li>
                    <a href="confirmed-order.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>

                <div class="white-box analytics-info-cs">
                  <?php
                  $sql4 = "SELECT * from  tblproducts";
                  $query4 = $dbh->prepare($sql4);
                  $query4->execute();
                  $results4 = $query4->fetchAll(PDO::FETCH_OBJ);
                  $totproduct = $query4->rowCount();
                  ?>
                  <h3 class="box-title">Total Books</h3>
                  <ul class="list-inline two-part-sp">
                    <li>
                      <div><i class="fa fa-globe" aria-hidden="true" style="color: red"></i></div>
                    </li>
                    <li class="text-right sp-cn-r"> <span class="counter text-success" style="color: blue">(<?php echo htmlentities($totproduct); ?>)</span></li>
                    <a href="manage-products.php"><STRONG> View Detail</STRONG></a>
                  </ul>
                </div>

                
              </div>
              </div>
            </div>
          </div>
        </div>


        <?php include_once('includes/footer.php'); ?>
      </div>

      <!-- jquery
		============================================ -->
      <script src="js/vendor/jquery-1.11.3.min.js"></script>
      <!-- bootstrap JS
		============================================ -->
      <script src="js/bootstrap.min.js"></script>
      <!-- wow JS
		============================================ -->
      <script src="js/wow.min.js"></script>
      <!-- price-slider JS
		============================================ -->
      <script src="js/jquery-price-slider.js"></script>
      <!-- meanmenu JS
		============================================ -->
      <script src="js/jquery.meanmenu.js"></script>
      <!-- owl.carousel JS
		============================================ -->
      <script src="js/owl.carousel.min.js"></script>
      <!-- sticky JS
		============================================ -->
      <script src="js/jquery.sticky.js"></script>
      <!-- scrollUp JS
		============================================ -->
      <script src="js/jquery.scrollUp.min.js"></script>
      <!-- mCustomScrollbar JS
		============================================ -->
      <script src="js/scrollbar/jquery.mCustomScrollbar.concat.min.js"></script>
      <script src="js/scrollbar/mCustomScrollbar-active.js"></script>
      <!-- metisMenu JS
		============================================ -->
      <script src="js/metisMenu/metisMenu.min.js"></script>
      <script src="js/metisMenu/metisMenu-active.js"></script>
      <!-- morrisjs JS
		============================================ -->
      <script src="js/morrisjs/raphael-min.js"></script>
      <script src="js/morrisjs/morris.js"></script>
      <script src="js/morrisjs/morris-active.js"></script>
      <!-- morrisjs JS
		============================================ -->
      <script src="js/sparkline/jquery.sparkline.min.js"></script>
      <script src="js/sparkline/jquery.charts-sparkline.js"></script>
      <!-- calendar JS
		============================================ -->
      <script src="js/calendar/moment.min.js"></script>
      <script src="js/calendar/fullcalendar.min.js"></script>
      <script src="js/calendar/fullcalendar-active.js"></script>
      <!-- plugins JS
		============================================ -->
      <script src="js/plugins.js"></script>
      <!-- main JS
		============================================ -->
      <script src="js/main.js"></script>
  </body>

  </html><?php }  ?>