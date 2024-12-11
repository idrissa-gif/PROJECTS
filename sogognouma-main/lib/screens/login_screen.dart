import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/services.dart';

class LoginScreen extends StatefulWidget {
  @override
  _LoginScreenState createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  final TextEditingController _phoneNumberController = TextEditingController();
  final TextEditingController _pinController = TextEditingController();

  Future<void> _login() async {
    try {
      // Sign in the user with phone number and PIN
      UserCredential userCredential = await FirebaseAuth.instance
          .signInWithCredential(
        PhoneAuthProvider.credential(
          verificationId: _verificationId!,
          smsCode: _pinController.text,
        ),
      );

      // If sign-in is successful, navigate to profile screen
      Navigator.pushReplacementNamed(context, '/profile');
    } catch (e) {
      // Handle sign-in errors
      print('Failed to sign in: $e');
      // Show an error message to the user
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Failed to sign in. Please try again.')),
      );
    }
  }

  String? _verificationId;

  Future<void> _verifyPhoneNumber() async {
    try {
      // Verify phone number
      PhoneVerificationCompleted verificationCompleted =
          (PhoneAuthCredential phoneAuthCredential) async {
        await FirebaseAuth.instance.signInWithCredential(phoneAuthCredential);
        // If sign-in is successful, navigate to profile screen
        Navigator.pushReplacementNamed(context, '/profile');
      };

      PhoneVerificationFailed verificationFailed =
          (FirebaseAuthException authException) {
        // Handle verification failed scenario
        print('Phone number verification failed. Code: ${authException
            .code}. Message: ${authException.message}');
        // Show an error message to the user
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text(
              'Phone number verification failed. Please try again.')),
        );
      };

      PhoneCodeSent codeSent = (String verificationId, int? resendToken) {
        // Save the verification ID
        _verificationId = verificationId;
        // Navigate to PIN entry screen
        Navigator.pushReplacementNamed(context, '/pin_entry');
      };

      PhoneCodeAutoRetrievalTimeout codeAutoRetrievalTimeout =
          (String verificationId) {
        // Save the verification ID
        _verificationId = verificationId;
        // Show a message to the user
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(
              content: Text('Verification code has been sent to your phone.')),
        );
      };

      // Request phone number verification
      await FirebaseAuth.instance.verifyPhoneNumber(
        phoneNumber: _phoneNumberController.text,
        verificationCompleted: verificationCompleted,
        verificationFailed: verificationFailed,
        codeSent: codeSent,
        codeAutoRetrievalTimeout: codeAutoRetrievalTimeout,
      );
    } catch (e) {
      // Handle phone number verification errors
      print('Failed to verify phone number: $e');
      // Show an error message to the user
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
            content: Text('Failed to verify phone number. Please try again.')),
      );
    }
  }

  void _navigateToSignUp() {
    // Navigate to sign-up screen
    Navigator.pushReplacementNamed(context, '/request_phone_number_otp');
  }

  void _navigateToForgotPIN() {
    // Navigate to forgot PIN screen
    Navigator.pushReplacementNamed(context, '/forgot_pin');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Login'),
        // leading:ClipOval(child: Image.asset('lib/assets/images/logo.png')),
      ),
      body: Padding(
        padding: EdgeInsets.all(20),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,

          children: [
            FractionallySizedBox(
              widthFactor: 0.3, // Adjust this factor as needed
              child: Icon(
                Icons.account_circle,
                size: 50,
              ),
            ),
            SizedBox(height: 20),
            TextFormField(
              controller: _phoneNumberController,
              keyboardType: TextInputType.phone,
              inputFormatters: [
                FilteringTextInputFormatter.digitsOnly,
                LengthLimitingTextInputFormatter(8)
              ],
              decoration: InputDecoration(
                labelText: 'Phone Number',
                hintText: 'Enter your phone number',
                icon: Icon(Icons.phone),
              ),

            ),
            SizedBox(height: 20),
            TextFormField(
              controller: _pinController,
              keyboardType: TextInputType.visiblePassword,
              obscureText: true,
              inputFormatters: [
                FilteringTextInputFormatter.digitsOnly,
                LengthLimitingTextInputFormatter(6)
              ],
              decoration: InputDecoration(
                labelText: 'Password',
                hintText: 'Enter your password',
                icon: Icon(Icons.lock),
              ),
            ),
            SizedBox(height: 20),
            Align(
              alignment: Alignment.centerRight,
              child: TextButton(
                onPressed: _navigateToForgotPIN,
                child: Text(
                  'Forgot PIN?',
                  style: TextStyle(color: Colors.red),
                ),
              ),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _login,
              style: ButtonStyle(
                backgroundColor: MaterialStateProperty.all<Color>(Colors.green),
              ),
              child: Text('Login'),
            ),
            SizedBox(height: 10),
            TextButton(
              onPressed: _navigateToSignUp,
              child: Text('Sign Up'),
            ),
          ],
        ),
      ),
    );
  }
}
