import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:sogognouma/screens/cart_screen.dart';
import 'package:sogognouma/screens/home_screen.dart';
import 'package:sogognouma/screens/login_screen.dart';
import 'package:sogognouma/screens/profile_screen.dart';
import 'package:sogognouma/utils/routes.dart';
import 'package:sogognouma/widgets/tab_navigation.dart';
import 'package:sogognouma/firebase_options.dart';



Future<void> main() async{
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  get isLogin => false;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'SogoGnouma',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: TabNavigation(
        tabs: [
          // Add your tab content widgets here
          HomeScreen(),
          CartScreen(),
          isLogin ? ProfileScreen() : LoginScreen(),
        ],
        tabTitles: [
          'Home',
          'Cart',
          'Account',
          'Orders',
          // Add titles for your tabs here
        ],
      ),
      routes: routes,
      // Remove initialRoute since we are using TabNavigation as the home screen
      // initialRoute: '/', // Set the initial route
    );
  }
}
