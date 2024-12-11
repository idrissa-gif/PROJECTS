#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
class LeagueInfo
{
private:
	MYSQL* db_conn;
	std::string Name;
	int No_of_team;
	int yearOfFormation;
public:
	LeagueInfo(const  std::string = "localhost", const std::string = "", const std::string = "", const std::string = "");
	void setinfo();
	void setNoOFTeam();
	void getinfo();

};

