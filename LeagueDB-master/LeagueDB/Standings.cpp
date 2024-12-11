#include "Standings.h"
#ifndef TEAM_H
#include"Team.h"
#endif
#ifndef VECTOR_H
#include<vector>
#endif

#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
#ifndef __IOSTREAM_H
#include<iostream>
#endif // !__IOSTREAM_H
#ifndef __SSTREAM_H
#include<sstream>
#endif 
#ifndef __IOMANIP_H
#include <iomanip>
#endif 

Standings::Standings(const std::string host, const std::string user, const std::string passwd, const std::string database)
{

	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
}

Standings::~Standings()
{
}

void Standings::updateStandingsTable()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query1, query2, reset;
	query1 << "insert into standings(TeamName) select TeamName from teamdb ";
	query2 << "update standings set MatchPlayed=0,Wins=0,Draws=0,Losses=0,Goalscored=0,Goalsconceded=0,Goaldifference=0,Points=0";
	reset << "truncate standings";
	if (!mysql_query(db_conn, reset.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		std::cout << "Successfully " << std::endl;
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed to update 1";
	if (!mysql_query(db_conn, query1.str().c_str()))
	{
		std::cout << "Successfully Updated" << std::endl;
	}
	else
		std::cout << "Failed to update 2";
	if (!mysql_query(db_conn, query2.str().c_str()))
	{
		std::cout << "Successfully Updated" << std::endl;
	}
	else
		std::cout << "Failed to update 3";
}

void Standings::TeamWithMostPoints()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Points from standings where Points = (select MAX(Points) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		std::cout << "Teams with the most points\n";
		std::cout << "Team Name " << std::setw(21) << "Points " << std::endl;

		while (row = mysql_fetch_row(rset))
		{

			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}
void Standings::TeamWithLeastPoints()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Points from standings where Points = (select MIN(Points) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);

		std::cout << "Teams with the Least points\n";
		std::cout << "Team Name " << std::setw(21) << "Points " << std::endl;
		while (row = mysql_fetch_row(rset))
		{
			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::TeamAtSpecificPos(int Pos)
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	std::string position;
	position = std::to_string(Pos);
	query << "select TeamName from standings where ROW_NUM()='" + std::to_string(Pos) + "' order by Points";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		std::cout << "Team at position " << Pos <<" is "<< row[0]<<std::endl;
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::TeamWithMostGoal()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Goalscored from standings where Goalscored = (select MAX(Goalscored) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);

		std::cout << "Teams with the Most Goals Scored\n";
		std::cout << "Team Name " << std::setw(21) << "Goals Scored " << std::endl;
		
		while (row = mysql_fetch_row(rset))
		{
			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::TeamWithLeastGoal()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Goalscored from standings where Goalscored = (select MIN(Goalscored) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);

		std::cout << "Teams with the Least Goal\n";
		std::cout << "Team Name " << std::setw(21) << "Least Goal " << std::endl;
		while (row = mysql_fetch_row(rset))
		{
			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::TeamWithHighestDifference()
{
MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Goaldifference from standings where Goaldifference = (select MAX(Goaldifference) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);

		std::cout << "Teams with the Highest Goal Difference\n";
		std::cout << "Team Name " << std::setw(21) << "Goal Difference " << std::endl;
		
		while (row = mysql_fetch_row(rset))
		{
			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::TeamWithLowestDifference()
{
MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream query;
	query << "select TeamName , Goaldifference from standings where Goaldifference = (select MIN(Goaldifference) from standings) ";
	if (!mysql_query(db_conn, query.str().c_str()))
	{
		rset = mysql_use_result(db_conn);

		std::cout << "Teams with the Lowest Goal Difference\n";
		std::cout << "Team Name " << std::setw(21) << "Goal Difference " << std::endl;
		
		while (row = mysql_fetch_row(rset))
		{
			std::cout << row[0] << std::setw(21) << row[1] << std::endl;

		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed";
}

void Standings::getstanding()
{
	system("Standings\\x64\\Debug\\Standings.exe");
}
