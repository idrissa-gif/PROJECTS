// lib/widgets/tab_navigation.dart
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class TabNavigation extends StatefulWidget {
  final List<Widget> tabs;
  final List<String> tabTitles;

  TabNavigation({required this.tabs, required this.tabTitles});

  @override
  _TabNavigationState createState() => _TabNavigationState();
}

class _TabNavigationState extends State<TabNavigation> with SingleTickerProviderStateMixin {
  late TabController _tabController;

  @override
  void initState() {
    super.initState();
    _tabController = TabController(length: widget.tabs.length, vsync: this);
  }

  @override
  void dispose() {
    _tabController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: TabBarView(
        controller: _tabController,
        children: widget.tabs,
      ),
      bottomNavigationBar: BottomNavigationBar(
        items: _buildBottomNavBarItems(),
        onTap: (index) {
          _tabController.animateTo(index);
        },
      ),
    );
  }

  List<BottomNavigationBarItem> _buildBottomNavBarItems() {
    List<BottomNavigationBarItem> navBarItems = [];
      navBarItems.add(
        BottomNavigationBarItem(
          label: widget.tabTitles[0],
          icon: Icon(Icons.home), // Replace 'Icons.tab' with appropriate icons
        ),
      );
    navBarItems.add(
      BottomNavigationBarItem(
        label: widget.tabTitles[1],
        icon: Icon(Icons.add_shopping_cart), // Replace 'Icons.tab' with appropriate icons
      ),
    );
    navBarItems.add(
      BottomNavigationBarItem(
        label: widget.tabTitles[2],
        icon: Icon(Icons.account_circle), // Replace 'Icons.tab' with appropriate icons
      ),
    );
    return navBarItems;
  }
}
