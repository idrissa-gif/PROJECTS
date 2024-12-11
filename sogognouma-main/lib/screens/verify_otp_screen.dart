import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';

class OTPScreen extends StatefulWidget {
  final String phoneNumber= "+8801612618109";

  @override
  _OTPScreenState createState() => _OTPScreenState();
}

class _OTPScreenState extends State<OTPScreen> {
  final TextEditingController _otpController = TextEditingController();
  late String _verificationId;

  Future<void> _verifyPhoneNumber() async {
    await FirebaseAuth.instance.verifyPhoneNumber(
      phoneNumber: widget.phoneNumber,
      verificationCompleted: (PhoneAuthCredential credential) async {
        await FirebaseAuth.instance.signInWithCredential(credential);
        // Verification is completed automatically
        // You can redirect to the signup page here if needed
      },
      verificationFailed: (FirebaseAuthException e) {
        // Handle verification failed scenario
        print('Phone number verification failed. Code: ${e.code}. Message: ${e.message}');
        // You can display an error message to the user
      },
      codeSent: (String verificationId, int? resendToken) {
        _verificationId = verificationId;
      },
      codeAutoRetrievalTimeout: (String verificationId) {
        _verificationId = verificationId;
        // Show a message to the user that the code has been auto-retrieved
      },
      timeout: Duration(seconds: 60), // Timeout duration for code auto-retrieval
    );
  }

  Future<void> _submitOTP() async {
    try {
      PhoneAuthCredential credential = PhoneAuthProvider.credential(
        verificationId: _verificationId,
        smsCode: _otpController.text,
      );

      // Sign in with the received OTP
      await FirebaseAuth.instance.signInWithCredential(credential);

      // Verification is successful, you can redirect to the signup page here
      Navigator.pushReplacementNamed(context, '/signup');
    } catch (e) {
      // Handle sign-in errors
      print('Failed to sign in with OTP: $e');
      // Show an error message to the user
    }
  }

  @override
  void initState() {
    super.initState();
    _verifyPhoneNumber();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('OTP Verification'),
      ),
      body: Padding(
        padding: EdgeInsets.all(20),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Enter the OTP sent to ${widget.phoneNumber}',
              style: TextStyle(fontSize: 18),
              textAlign: TextAlign.center,
            ),
            SizedBox(height: 20),
            TextFormField(
              controller: _otpController,
              keyboardType: TextInputType.number,
              maxLength: 6,
              decoration: InputDecoration(
                labelText: 'OTP',
                hintText: 'Enter OTP',
              ),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _submitOTP,
              child: Text('Submit OTP'),
            ),
          ],
        ),
      ),
    );
  }
}
