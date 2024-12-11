#include "Fixture.h"
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
Fixture::Fixture(const std::string host, const std::string user, const std::string passwd, const std::string database)
{

	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
}
Fixture::~Fixture()
{
	mysql_close(db_conn);
}
int& Fixture::gethomeTeamGoal()
{
	return homeTeamGoal;
}

int& Fixture::getawayTeamGoal()
{
	return awayTeamGoal;
}

int& Fixture::getmatchday()
{
	return matchday;
}

void Fixture::getligue()
{
	system("Graphic\\x64\\Debug\\Graphic.exe");
}



void Fixture::generateSchedule()
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	int count;
	std::stringstream ss, cnt , reset;
	cnt << "select count(*) from teamdb";
	reset << "truncate fixturedb";

	if (!mysql_query(db_conn, cnt.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		count = std::stoi(row[0]);
		mysql_free_result(rset);
	}
	else 
		std::cout << "Failed ";
	
	if (!mysql_query(db_conn, reset.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		std::cout << "Successful" <<std::endl;
		mysql_free_result(rset);
	}
	else 
		std::cout << "Failed ";

	int i = 0;
	std::vector<std::string> teamarr;
	ss << "select * from teamdb";
	if (!mysql_query(db_conn, ss.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		while ((row = mysql_fetch_row(rset)))
		{
			teamarr.push_back(row[0]);
		}
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed to find the team";
	
	for (int i = 0; i<count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (i != j)
			{
				std::string query = "INSERT INTO fixturedb ( hometeam , awayteam) VALUES ('" + teamarr[i]+ "','" + teamarr[j]+"')";
				if (mysql_query(db_conn, query.c_str()))
				{
					std::cout << "Failed to create Schedule!\n" << mysql_error(db_conn) << std::endl;
				}

				else
					std::cout << "Schedule creation successful.\n";
			}
		}
	}

}