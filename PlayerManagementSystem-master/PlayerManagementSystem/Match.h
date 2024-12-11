#pragma once
#include"Player.h"

class Match
{
private:
	int home_team_goals;
	int away_team_goals;
	Player man_of_match;
public:
	int gethome_team_goals();
	int getaway_team_goals();
	Player getman_of_match();

    void sethome_team_goals(int home_team_goals);
    void setaway_team_goals(int away_team_goals);
	void setman_of_match(Player man_of_match);
};

