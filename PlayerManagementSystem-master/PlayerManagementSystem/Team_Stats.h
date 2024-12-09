#pragma once
class Team_Stats
{
private:
	int point;
	int rank;
	int wins;
	int losts;
	int draws;
	int goals_scored;
	int goals_conceded;
public:
	int getpoint();
	int getrank();
	int getwins();
	int getlosts();
	int getdraws();
	int getgoals_scored();
	int getgoals_conceded();	
	
	void setpoint(int point);
	void setrank(int rank);
	void setwins(int wins);
	void setlosts(int losts);
    void setdraws(int draws);
	void setgoals_scored(int goals_scored);
	void setgoals_conceded(int goals_conceded);

};

