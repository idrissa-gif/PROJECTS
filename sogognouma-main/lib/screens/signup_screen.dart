import 'package:flutter/material.dart';
import 'package:datetime_picker_formfield/datetime_picker_formfield.dart';
import 'package:intl/intl.dart';
import 'package:sogognouma/models/user.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/services.dart';
import 'dart:convert';
import 'package:crypto/crypto.dart';


class SignupScreen extends StatefulWidget {
  @override
  _SignupScreenState createState() => _SignupScreenState();
}

class _SignupScreenState extends State<SignupScreen>{
  final TextEditingController _firstName = TextEditingController();
  final TextEditingController _lastName = TextEditingController();
  final TextEditingController _email = TextEditingController();
  final TextEditingController _phoneNumber = TextEditingController();
  final TextEditingController _address = TextEditingController();
  final TextEditingController _dateOfBirth = TextEditingController();
  final TextEditingController _gender = TextEditingController();
  final TextEditingController _pin = TextEditingController();
  final TextEditingController _pin_conform = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      resizeToAvoidBottomInset : false,
      appBar: AppBar(
        title: Text('Sign Up'),
      ),
      body: SingleChildScrollView(
        child:Padding(
          padding: EdgeInsets.all(20),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
                'Create a new account',
                style: TextStyle(fontSize: 18),
              ),
              SizedBox(height: 20),
              // Add your sign-up form fields here
              TextFormField(
                controller: _firstName,
                decoration: InputDecoration(
                  labelText: 'First Name',
                  hintText: 'Enter your first name',
                  icon: Icon(Icons.account_circle),
                  iconColor: Colors.green,
                ),
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _lastName,
                decoration: InputDecoration(
                  labelText: 'Last Name',
                  hintText: 'Enter your last name',
                  icon: Icon(Icons.man_sharp),
                  iconColor: Colors.green,
                ),
              ),
              SizedBox(height: 10),
              DateTimeField(
                controller: _dateOfBirth,
                format: DateFormat("yyyy-MM-dd"),
                decoration: InputDecoration(
                  labelText: 'Date of Birth',
                  hintText: 'Enter your date of birth',
                  icon: Icon(Icons.cake),
                  iconColor: Colors.green,
                ),
                onShowPicker: (context, currentValue) {
                  return showDatePicker(
                    context: context,
                    initialDate: currentValue ?? DateTime.now(),
                    firstDate: DateTime(1900),
                    lastDate: DateTime.now(),
                  );
                },
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _email,
                decoration: InputDecoration(
                  labelText: 'Email',
                  hintText: 'Enter your email address',
                  icon: Icon(Icons.email),
                  iconColor: Colors.green,
                ),
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _phoneNumber,
                inputFormatters: [
                  FilteringTextInputFormatter.digitsOnly,
                  LengthLimitingTextInputFormatter(8)
                ],
                decoration: InputDecoration(
                  labelText: 'Phone Number',
                  hintText: 'Enter your phone number',
                  icon: Icon(Icons.phone),
                  iconColor: Colors.green,
                ),
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _address,
                keyboardType: TextInputType.streetAddress,
                decoration: InputDecoration(
                  labelText: 'Address',
                  hintText: 'Enter your address',
                  icon: Icon(Icons.home),
                  iconColor: Colors.green,
                ),
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _pin,
                keyboardType: TextInputType.visiblePassword,
                inputFormatters: [
                  FilteringTextInputFormatter.digitsOnly,
                  LengthLimitingTextInputFormatter(6)
                ],
                decoration: InputDecoration(
                  labelText: 'PIN',
                  hintText: 'Enter your PIN',
                  icon: Icon(Icons.pin),
                  iconColor: Colors.green,
                ),
                obscureText: true,
              ),
              SizedBox(height: 10),
              TextFormField(
                controller: _pin_conform,
                keyboardType: TextInputType.visiblePassword,
                inputFormatters: [
                  FilteringTextInputFormatter.digitsOnly,
                  LengthLimitingTextInputFormatter(6)
                ],
                decoration: InputDecoration(
                  labelText: 'PIN comfirm',
                  hintText: 'Enter your PIN confirm',
                  icon: Icon(Icons.pin),
                  iconColor: Colors.green,
                ),
                obscureText: true,
              ),
              SizedBox(height: 20),
              ElevatedButton(
                onPressed: () {
                  // Add sign-up logic here
                  _handleSignUp(context);
                },
                child: Text('Sign Up'),
              ),
            ],
          ),
        ),
      ),
    );
  }
  void _handleSignUp(BuildContext context) async {
    // Get form data
    // For brevity, only first name, last name, email, and date of birth are shown
    String firstName = _firstName.text; // Replace with data from form field
    String lastName = _lastName.text; // Replace with data from form field
    String email = _email.text; // Replace with data from form field
    DateTime dateOfBirth = DateTime.parse(
        _dateOfBirth.text); // Replace with data from form field
    String phone = _phoneNumber.text;
    String address = _address.text;
    String gender = _gender.text;
    String hashedPin = sha256.convert(utf8.encode(_pin.text)).toString();
    String hashedPinConform = sha256.convert(utf8.encode(_pin_conform.text)).toString();
    if (hashedPin == hashedPinConform) {
      // Create user object
      User user = User(
        firstName: firstName,
        lastName: lastName,
        email: email,
        phoneNumber: phone,
        address: address,
        dateOfBirth: dateOfBirth,
        gender: gender,
        pin: hashedPin,
      );

      // Convert user object to JSON
      Map<String, dynamic> userData = user.toJson();

      try {
        // Send data to Firebase
        await FirebaseFirestore.instance.collection('users').add(userData);

        // Show success message
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('User signed up successfully')),
        );

        // Navigate to another screen or perform any other actions
      } catch (e) {
        // Show error message
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Failed to sign up. Please try again.')),
        );
      }
    }
    else
      {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('The pins does not match. Please try again.')),
        );
      }
  }
}