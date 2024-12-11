#pragma once
#include<iostream>
using namespace std;
class League
{
private:
	string name;
	int no_team;
public:
	string getname();
	int getno_team();

	void setname(string name);
	void setno_team(int no_team);
};

