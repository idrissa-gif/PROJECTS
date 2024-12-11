import 'package:flutter/material.dart';

class ProfileScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('User Profile'),
        leading: ClipOval(
          child: Image.asset(
            'assets/images/logo.png',
          ),
        ),
        backgroundColor: Colors.blue,
      ),
      body: Center(
        child: Text('Profile Screen'),
      ),
    );
  }
}
