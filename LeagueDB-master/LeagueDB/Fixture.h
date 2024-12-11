#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h

class Fixture
{
private:
	MYSQL *db_conn;

	int homeTeamGoal;
	int awayTeamGoal;
	int matchday;
public:
	Fixture (const  std::string = "localhost", const std::string = "", const std::string = "", const std::string = "");
	~Fixture();
	int& gethomeTeamGoal();
	int& getawayTeamGoal();
	void generateSchedule();
	int& getmatchday();
	void getligue();
	//void updateStandingsTable();
};

