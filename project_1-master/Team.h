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
	Team(string name, int no_players,string stadium) :name(name), no_players(no_players), stadium(stadium)
	{

	}

};

