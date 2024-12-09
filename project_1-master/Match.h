#pragma once
#include<iostream>
#include"Player.h"
using namespace std;

class Match
{
private:
	int home_team_goals;
	int away_team_goals;
	Player man_of_match;
public:
	Match(int home_team_goals, int away_team_goals, Player man_of_match) :home_team_goals(home_team_goals), away_team_goals(away_team_goals), man_of_match(man_of_match)
	{

	}
};

