// lib/screens/home_screen.dart
import 'package:flutter/material.dart';
import 'package:sogognouma/screens/cart_screen.dart';
import 'package:sogognouma/screens/profile_screen.dart';
import 'package:sogognouma/widgets/tab_navigation.dart';

class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Home'),
        leading: ClipOval(
          child: Image.asset(
            'assets/images/logo.png',
          ),
        ),
        backgroundColor: Colors.blue,
      ),

      body: Center(
        child: Text('Home'),
      ),
    );
  }
}