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
	Team_Stats(int point, int rank, int wins, int losts, int draws, int goals_scored, int goals_conceded) :point(point), rank(rank), wins(wins), losts(losts), draws(draws), goals_scored(goals_scored), goals_conceded(goals_conceded)
	{

	}

};

