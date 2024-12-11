#include "LeagueInfo.h"
#ifndef __IOSTREAM_H
#include<iostream>
#endif // !__IOSTREAM_H
#ifndef __SSTREAM_H
#include<sstream>
#endif // !__SSTREAM_H
#ifndef __CSTDLIB_H
#include <cstdlib>
#endif // !__CSTDLIB_H
#ifndef __IOMANIP_H
#include <iomanip>
#endif // !__IOMANIP_H
#ifndef __FSTREAM_H
#include <fstream>
#endif
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
#ifndef TEAM_H
#include "Team.h"
#endif

LeagueInfo::LeagueInfo(const std::string host, const std::string user, const std::string passwd, const std::string database)
{
	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
}

void LeagueInfo::setinfo()
{
	std::ofstream Storeinfo("LeagueInfo.txt");
	std::cout << "Enter The League information" << std::endl;
	std::cout << "Name:";
	std::cin >> Name;
	std::cout << "Year of formation: ";
	std::cin >> yearOfFormation;
	Storeinfo << Name << ' ' << yearOfFormation;
	Storeinfo.close();
}


void LeagueInfo::setNoOFTeam()
{
	std::ofstream Storeinfo("NoOfTeam.txt");
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::string query = "SELECT COUNT(*) FROM teamdb";
	if (mysql_query(db_conn, query.c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		No_of_team = std::atoi(row[0]);
		std::cout << "Failed!\n" << mysql_error(db_conn) << std::endl;
	}

	else
		std::cout << "\nTeam creation successful.\n";

	Storeinfo << No_of_team;
	Storeinfo.close();
}

void LeagueInfo::getinfo()
{
	std::ifstream Storeteam("NoOfTeam.txt");
	Storeteam >> No_of_team;
	Storeteam.close();
	std::ifstream Storeinfo("LeagueInfo.txt");
	Storeinfo >> Name >> yearOfFormation;
	Storeinfo.close();
	std::cout << "League Name: " << Name << "  Year of Formation: " << yearOfFormation << "  Number of teams: " << No_of_team << std::endl;;
	
}
