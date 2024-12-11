#include "Player.h"
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
Player::Player(const std::string host, const std::string user, const std::string passwd, const std::string database)
{
	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
	readcount();
}

Player::~Player()
{
	mysql_close(db_conn);
}

std::string& Player::getplayerfirstname()
{
	return playerFirstname;
}

std::string& Player::getplayerlastname()
{
	return playerLastname;
}

int& Player::getplayerID()
{
	return playerID;
}

int& Player::getplayerage()
{
 return age;
}


float& Player::getheight()
{
	return height;
}

int& Player::getrating()
{
	return rating;
}

std::string& Player::getnationality()
{
	return nationality;
}

std::string Player::getdominantleg(int dl)
{
	if (dl == left)
		return "left";
	else
		return "right";
}

double& Player::getmarketvalue()
{
	return marketValue;
}

double& Player::getannaualsalary()
{
	return annualSalary;
}

void Player::insert(std::string position)
{
	std::string teamName;
	int leg;
	std::cout << "=============================================Enter The Player Informations=============================================" << std::endl;
	getplayerID()=++pcount;
	
	getchar();
	std::cout << "Enter the Player firstname: ";
	std::getline(std::cin, getplayerfirstname());
	std::cout << "Enter the Player lastname: ";
	std::getline(std::cin, getplayerlastname());
	std::cout << "Enter The Player Nationality: ";
	std::cin >> getnationality();
	getchar();
	std::cout << "Enter the Player Team: ";
	std::getline(std::cin, teamName);
	std::cout << "Enter the player age: ";
	std::cin >> getplayerage();
	std::cout << "Enter the player weight: ";
	std::cin >> getweight();
	std::cout << "Enter the player height: ";
	std::cin >> getheight();
	std::cout << "Enter the player rating: ";
	std::cin >> getrating();
	std::cout << "Enter the player dominant leg(0 - left , 1 - right): ";
	std::cin >> leg;
	std::cout << "Enter the player market value: ";
	std::cin >> getmarketvalue();
	std::cout << "Enter the player salary: ";
	std::cin >> getannaualsalary();

	std::string query = "INSERT INTO playerdb(PID,Pfirstname,Plastname,age,weight,height,rating,position,nationality,dominant_leg,marketvalue,annualsalary,team) VALUES ( '" + std::to_string(playerID) + "', '" + playerFirstname + "','" + playerLastname + "', '" + std::to_string(age) + "', '" + std::to_string(weight) + "', '" + std::to_string(height) + "', '" + std::to_string(rating) + "', '" + position + "', '" + nationality + "', '" + getdominantleg(leg) + "', '" + std::to_string(marketValue) + "', '" + std::to_string(annualSalary) + "', '" + teamName + "')";

	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Player!\n" << mysql_error(db_conn) << std::endl;
	}

	else
	{
		std::cout << "Player creation successful.\n";
		writecount(pcount);
	}
		
}

void Player::deleteplayer(int id)
{
	std::stringstream ss;
	ss << "DELETE FROM playerdb WHERE MID= '" + std::to_string(id) + "'";
	if (mysql_query(db_conn, ss.str().c_str()))
		std::cout << "Failed to delete the player!\n";
	else
		std::cout << "Player successfully delete.\n";
}

void Player::searchplayer(int id)
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream ss;
	ss << "select  *FROM playerdb WHERE PID = '" + std::to_string(id) + "'";
	if (!mysql_query(db_conn, ss.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		std::cout << "Successfully Find\n";
		std::cout << "Player id: " << row[0] << std::endl;
		std::cout << "Firstname: " << row[1] << std::endl;
		std::cout << "Lastname: " << row[2] << std::endl;
		std::cout << "Age: " << row[3] << std::endl;
		std::cout << "Weight: " << row[4] << std::endl;
		std::cout << "Height: " << row[5] << std::endl;
		std::cout << "Rating: " << row[6] << std::endl;
		std::cout << "Position: " << row[7] << std::endl;
		std::cout << "Nationality: " << row[8] << std::endl;
		std::cout << "Dominant leg: " << row[9] << std::endl;
		std::cout << "Market value: " << row[10] << std::endl;
		std::cout << "Annual Salary: " << row[11] << std::endl;
		std::cout << "Player Team: " << row[12] << std::endl;
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed to find the player\n";
}

void Player::printall()
{
	system("Player\\x64\\Debug\\Player.exe");
}

void Player::editplayer(int id)
{
	std::string teamName;
	int leg, pos;
	std::cout << "=============================================Enter The Player Informations=============================================" << std::endl;
	getchar();
	std::cout << "Enter the Player firstname: ";
	std::getline(std::cin, getplayerfirstname());
	std::cout << "Enter the Player lastname: ";
	std::getline(std::cin, getplayerlastname());
	std::cout << "Enter The Player Nationality: ";
	std::cin >> getnationality();
	getchar();
	std::cout << "Enter the Player Team: ";
	std::getline(std::cin, teamName);
	std::cout << "Enter the player age: ";
	std::cin >> getplayerage();
	std::cout << "Enter the player weight: ";
	std::cin >> getweight();
	std::cout << "Enter the player height: ";
	std::cin >> getheight();
	std::cout << "Enter the player rating: ";
	std::cin >> getrating();
	std::cout << "Enter the player position: ";
	std::cin >> pos;
	std::cout << "Enter the player dominant leg(0 - left , 1 - right): ";
	std::cin >> leg;
	std::cout << "Enter the player market value: ";
	std::cin >> getmarketvalue();
	std::cout << "Enter the player salary: ";
	std::cin >> getannaualsalary();

	std::string query = "Update playerdb set Pfirstname = '" + playerFirstname + "',Plastname = '" + playerLastname + "',age = '" + std::to_string(age) + "',weight = '" + std::to_string(weight) + "',height = '" + std::to_string(height) + "',rating = '" + std::to_string(rating) + "',nationality = '" + nationality + "',dominant_leg = '" + getdominantleg(leg) + "',marketvalue = '" + std::to_string(marketValue) + "',annualsalary = '" + std::to_string(annualSalary) + "',team = '" + teamName + "' where PID = '"+std::to_string(id)+"'";
	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Player!\n" << mysql_error(db_conn) << std::endl;
	}

	else
		std::cout << "Player creation successful.\n";
}


float& Player::getweight()
{
	return weight;
}

int& Player::getcount()
{
	return pcount;
}
void Player::writecount(int count)
{
	std::ofstream StoreCount("PlayerID.txt");
	StoreCount  << getcount();
	StoreCount.close();
}
void Player::readcount()
{
	std::ifstream StoreCount("PlayerID.txt");
	StoreCount >> getcount();
	StoreCount.close();
}