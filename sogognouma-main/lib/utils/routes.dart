import 'package:flutter/material.dart';
import 'package:sogognouma/screens/home_screen.dart';
import 'package:sogognouma/screens/login_screen.dart';
import 'package:sogognouma/screens/request_phone_number_otp_screen.dart';
import 'package:sogognouma/screens/verify_otp_screen.dart';
import 'package:sogognouma/screens/product_details_screen.dart';
import 'package:sogognouma/screens/cart_screen.dart';
import 'package:sogognouma/screens/profile_screen.dart';
import 'package:sogognouma/screens/signup_screen.dart';

Map<String, WidgetBuilder> routes = {
  '/home':(context)=>HomeScreen(),
  '/product_details': (context) => ProductDetailsScreen(),
  '/cart': (context) => CartScreen(),
  '/profile': (context) => ProfileScreen(),
  '/login':(context) => LoginScreen(),
  '/signup':(context) => SignupScreen(),
  '/otp':(context) => OTPScreen(),
  '/request_phone_number_otp' : (context) =>RequestPhoneNumberOtpScreen(),
};
