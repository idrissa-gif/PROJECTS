#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h

class Standings
{
private:
	MYSQL* db_conn;
public:
	Standings(const  std::string = "localhost", const std::string = "", const std::string = "", const std::string = "");
	~Standings();
	void updateStandingsTable();
	void TeamWithMostPoints();
	void TeamWithLeastPoints();
	void TeamAtSpecificPos(int);
	void TeamWithMostGoal();
	void TeamWithLeastGoal();
	void TeamWithHighestDifference();
	void TeamWithLowestDifference();
	void getstanding();
};

