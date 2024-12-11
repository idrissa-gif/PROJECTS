#include "Team.h"
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
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

using namespace std;

Team::~Team()
{
	mysql_close(db_conn);
	delete P;
	delete M;
	delete B;
}


std::string& Team::getteamName()
{
	return teamName;
}

std::string& Team::getstadium()
{
	return stadium;
}

int& Team::getyearOfFormation()
{
	return yearOfFormation;
}

void Team::settername(std::string name)
{
	teamName = name;
}

Team::Team(const string host , const string user , const string passwd , const string database)
{
	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(),user.c_str(), passwd.c_str(), database.c_str(), 0,NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
}


void Team::insert()
{
	M = new Manager("localhost", "root", "test123", "leaguedb");
	B = new Budget();
	std::cout << "=============================================Enter The Team Information=============================================" << std::endl;
	std::cout << "Enter the Team Name: ";
	std::getline(std::cin, teamName);
	std::cout << "Enter the Team Stadium: ";
	std::getline(std::cin, stadium);
	std::cout << "Enter Year of Formation: ";
	std::cin >> yearOfFormation;
	std::cout << "Enter The Manager Id: ";
	std::cin >> M->getmanagerID();
    std::cout << "Enter the salary budget: ";
	std::cin >> B->getsalaryBudget();
    std::cout << "Enter the transfer budget: ";
	std::cin >> B->gettransferBudget();
	
	string query = "INSERT INTO teamdb(teamName , stadium , yearOfFormation , ManagerId , salaryBudget , transferBudget) VALUES ( '" + teamName + "', '" + stadium + "','"+to_string(yearOfFormation)+"', '" +to_string(M->getmanagerID())+ "', '" +to_string(B->getsalaryBudget())+ "', '" +to_string(M->getmanagerID())+ "')";

	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Team!\n" << mysql_error(db_conn) << std::endl;
	}
		
	else
		std::cout<<"Team creation successful.\n";
}

void Team::search(string tname)
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	stringstream ss;
	ss << "select  *FROM teamdb WHERE teamName = '" + tname + "'";
	if (!mysql_query(db_conn, ss.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		cout << "Successfully Find\n";
		cout << "Team Name: " <<row[0] << endl;
		cout << "Stadium: " << row[1] << endl;
		cout << "Year of formation: " << row[2]<<endl;
		cout << "Manager Id: " << row[3]<<endl;
		cout << "Salary Budget: " << row[4]<<endl;
		cout << "Transfer Budget: " << row[5]<<endl;
		mysql_free_result(rset);
	}
	else
		cout << "Failed to find the team";
}

void Team::edit(std::string tname)
{
	M = new Manager("localhost", "root", "test123", "leaguedb");
	B = new Budget();
	std::cout << "============================================= Enter The Team Information =============================================" << std::endl;
	std::cout << "Enter the Team Name: ";
	std::getline(std::cin, teamName);
	std::cout << "Enter the Team Stadium: ";
	std::getline(std::cin, stadium);
	std::cout << "Enter Year of Formation: ";
	std::cin >> yearOfFormation;
	std::cout << "Enter The Manager Id: ";
	std::cin >> M->getmanagerID();
	std::cout << "Enter the salary budget: ";
	std::cin >> B->getsalaryBudget();
	std::cout << "Enter the transfer budget: ";
	std::cin >> B->gettransferBudget();

	string query = "UPDATE teamdb SET teamName = '" + teamName + "' , stadium = '" + stadium + "' , yearOfFormation = '" + to_string(yearOfFormation) + "' , ManagerId = '" + to_string(M->getmanagerID()) + "' , salaryBudget = '" + to_string(B->getsalaryBudget()) + "' , transferBudget = '" + to_string(M->getmanagerID()) + "' WHERE teamName = '" + tname + "'";

	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Team!\n" << mysql_error(db_conn) << std::endl;
	}

	else
		std::cout << "Team Update successful.\n";
}

void Team::printall()
{
    system("Team\\x64\\Debug\\Team.exe");
}

void Team::deleteteam(string tname)
{
    stringstream ss;
	ss << "DELETE FROM teamdb WHERE teamName = '" + tname + "'";
    if (mysql_query(db_conn, ss.str().c_str()))
        cout << "Failed to delete the team!\n";
    else
        cout << "Team successfully delete.\n";
}


