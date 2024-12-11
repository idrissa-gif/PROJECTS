<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
  <title>Home</title>
  <!-- bootstrap css link -->
  <!-- CSS only -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-gH2yIJqKdNHPEq0n4Mqa/HGKIhSkIHeL5AyhkYV8i59U5AR6csBvApHHNl/vI1Bx" crossorigin="anonymous">
  <!-- swiper css link -->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.css">
  <!-- font awesome cdn link -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.1.2/css/all.min.css">
  <!-- custom css file link -->
  <link rel="stylesheet" href="../css/style.css">
  
  <link rel="canonical" href="https://getbootstrap.com/docs/5.2/examples/headers/">


</head>

<body class="HomeBody">

  <!-- footer session start  -->
  <section class="footer" style="background: url(../image/footer-bg.jpg) no-repeat;">
    <div class="box-container">

      <div class="box">
        <h3>Extra links</h3>
        <a href="#"><i class="fas fa-angle-right"></i> Ask Questions</a>
        <a href="#"><i class="fas fa-angle-right"></i> About us</a>
        <a href="#"><i class="fas fa-angle-right"></i> privacy policy</a>
        <a href="#"><i class="fas fa-angle-right"></i> terms of use</a>
      </div>
      <div class="box">
        <h3>contact info</h3>
        <a href="#"><i class="fas fa-phone"></i> +880 1612618109</a>
        <a href="#"><i class="fas fa-envelope"></i> Idrissa@iut-dhaka.edu</a>
        <a href="#"><i class="fas fa-envelope"></i> shalayuy@iut-dhaka.edu</a>
        <a href="#"><i class="fas fa-map"></i> Dhaka, Bangladesh</a>
      </div>
      <div class="box">
        <h3>Follow us</h3>
        <a href="#"><i class="fab fa-facebook"></i> facebook</a>
        <a href="#"><i class="fab fa-linkedin"></i> linkedin</a>
        <a href="#"><i class="fab fa-twitter"></i> twitter</a>
        <a href="#"><i class="fab fa-instagram"></i> instagram</a>
      </div>
    </div>
    <div class="credit">
      created by <span>Idrissa &amp; Nabil</span> | All right reversed!
    </div>

  </section>
  <!-- footer session end -->
  <!-- swiper js link -->
  <script src="https://cdn.jsdelivr.net/npm/swiper@8/swiper-bundle.min.js"></script>
  <!-- custom js file js -->
  <script src="../js/script.js"></script>
  <!-- script for bootstrap -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-A3rJD856KowSb7dwlZdYEkO39Gagi7vIsF0jrRAoQmDKKtQBHUuLZ9AsSv4jD4Xa" crossorigin="anonymous"></script>
  <script>
    const swiper = new Swiper('.swiper', {
      // Optional parameters
      loop: true,
      autoplay: {
        delay: 3000,
        disableOnInteration: false,
      },
      // If we need pagination
      pagination: {
        el: '.swiper-pagination',
        clickable: true,
      },

      // Navigation arrows
      navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
      },

     
    });
  </script>











</body>

</html>