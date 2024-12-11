#pragma once
#include<iostream>
using namespace std;
class League
{
private:
	string name;
	int no_team;
	int match_day;
public:
	League(string name, int no_team, int match_day) :name(name), no_team(no_team), match_day(match_day)
	{

	}
};

