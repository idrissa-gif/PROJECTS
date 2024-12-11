#pragma once
#include<iostream>
using namespace std;
class Team
{
private:
	string name;
	int no_players;
	string stadium;
public:
	string getname();
	int getno_players();
	string getstadium();

	void setname(string name);
	void setno_players(int no_players);
	void setstadium(string stadium);
};

