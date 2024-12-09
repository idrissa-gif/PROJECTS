#pragma once
class Player_Stats
{
private:
	double average_season_performance;
	int yellow_cards;
	int red_cards;
	int goals_scored;
	int number_of_match_played;
public:
	double getaverage_season_performance();
	int getyellow_cards();
	int getred_cards();
	int getgoals_scored();
	int getnumber_of_match_played();

	void setaverage_season_performance(double data);
	void setyellow_cards(int yellow_cards);
	void setred_cards(int red_cards);
	void setgoals_scored(int goals_scored) ;
	void setnumber_of_match_played(int no_match);
};

