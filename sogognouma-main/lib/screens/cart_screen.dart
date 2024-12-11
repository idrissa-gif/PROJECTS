// lib/screens/cart_screen.dart
import 'package:flutter/material.dart';

class CartScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blue,
        leading: ClipOval(
          child: Image.asset(
            'assets/images/logo.png',
          ),
        ),
        title: Text('Shopping Cart'),
      ),
      body: Center(
        child: Text(
          'Product Details Screen',
          style: TextStyle(fontSize: 24),
        ),
      ),
    );
  }
}
