#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef PLAYER_H
#include"Player.h"
#endif
#ifndef MANAGER_H
#include"Manager.h"
#endif
#ifndef BUDGET_H
#include"Budget.h"
#endif
#ifndef __MYSQL_H
#include<mysql.h>
#define MYSQL_H
#endif

class Team
{
private:
	MYSQL* db_conn;
	std::string teamName;
	std::string stadium;
	int yearOfFormation;
	Player *P;
	Manager* M;
	Budget* B;
public:
	
	Team(const  std::string = "localhost", const std::string = "", const std::string = "",const std::string = "");
	~Team();
	std::string& getteamName();
	std::string& getstadium();
	int& getyearOfFormation();
    void settername(std::string name);
	void printall();
	void deleteteam(std::string tname);
	void insert();
	void search(std::string tname);
	void edit(std::string tname);
};

