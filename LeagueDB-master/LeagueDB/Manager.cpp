#include "Manager.h"
#ifndef __STDIO_H
#include <stdio.h>
#endif
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
Manager::Manager(const std::string host, const std::string user , const std::string passwd, const std::string database)
{
	db_conn = mysql_init(NULL);
	if (!db_conn)
		std::cout << "MySQL initialization failed! " << std::endl;
	db_conn = mysql_real_connect(db_conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0);
	if (!db_conn) std::cout << "Connection error" << std::endl;
	readcount();
}

Manager::~Manager()
{
	mysql_close(db_conn);
}

int & Manager::getmanagerID()
{
	return managerID;
}

std::string& Manager::getmanagerfirstName()
{
	return managerfirstname;
}

std::string& Manager::getmanagerlastName()
{
	return managerlastname;
}

std::string& Manager::getmanagerNationality()
{
	return nationality;
}

double& Manager::getsalary()
{
	return salary;
}

int& Manager::getnoOfTrophies()
{
	return noOfTrophies;
}

void Manager::printall()
{
	system("Manager\\x64\\Debug\\Manager.exe");
}

void Manager::deleteteam(int id)
{
	std::stringstream ss;
	ss << "DELETE FROM managerdb WHERE MID= '" + std::to_string(id) + "'";
	if (mysql_query(db_conn, ss.str().c_str()))
		std::cout << "Failed to delete the manager!\n";
	else
		std::cout << "Manager successfully delete.\n";
}

void Manager::insert()
{
	std::string teamName;
	std::cout << "=============================================Enter The Manager Informations=============================================" << std::endl;
	getmanagerID()=++mcount;
	getchar();
	std::cout << "Enter the Manger firstname: ";
    std::getline(std::cin,getmanagerfirstName());
	std::cout << "Enter the Manager lastname: ";
	std:: getline(std::cin , getmanagerlastName());
	std::cout << "Enter The Manager Nationality: ";
	std::getline(std::cin, getmanagerNationality());
	std::cout << "Enter the manager Team: ";
	std::getline(std::cin,teamName);
	std::cout << "Enter the manager number of trophies: ";
	std::cin >> getnoOfTrophies();
	std::cout << "Enter the manager salary: ";
	std::cin >> getsalary();

	std::string query = "INSERT INTO managerdb(MID , Mfirstname ,Mlastname ,Mnationality ,Nooftrophies ,Mteam ,Msalary) VALUES ( '" + std::to_string(managerID) + "', '" + managerfirstname + "','" + managerlastname + "', '" + nationality + "', '" +std::to_string(noOfTrophies) + "', '" + teamName + "', '" +std::to_string(salary)+ "')";

	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Manager!\n" << mysql_error(db_conn) << std::endl;
	}

	else
	{
		writecount(mcount);
		std::cout << "Manager creation successful.\n";
	}
		
}

void Manager::search(int id)
{
	MYSQL_RES* rset;
	MYSQL_ROW row;
	std::stringstream ss;
	ss << "select  *FROM managerdb WHERE MID = '" +std::to_string(id)+ "'";
	if (!mysql_query(db_conn, ss.str().c_str()))
	{
		rset = mysql_use_result(db_conn);
		row = mysql_fetch_row(rset);
		std::cout << "Successfully Find\n";
		std::cout << "Manager id: " << row[0] << std::endl;
		std::cout << "firstname: " << row[1] << std::endl;
		std::cout << "lastname: " << row[2] << std::endl;
		std::cout << "Nationality: " << row[3] << std::endl;
		std::cout << "Number of trophies: " << row[4] << std::endl;
		std::cout << "Team: " << row[5] << std::endl;
		std::cout << "Salary: " << row[6] << std::endl;
		mysql_free_result(rset);
	}
	else
		std::cout << "Failed to find the manager\n";
}

void Manager::edit(int id)
{

	std::string teamName;
	std::cout << "=============================================Enter The Manager Informations=============================================" << std::endl;
	getchar();
	std::cout << "Enter the Manger firstname: ";
	std::getline(std::cin, getmanagerfirstName());
	std::cout << "Enter the Manager lastname: ";
	std::getline(std::cin, getmanagerlastName());
	std::cout << "Enter The Manager Nationality: ";
	std::getline(std::cin, getmanagerNationality());
	std::cout << "Enter the manager Team: ";
	std::getline(std::cin, teamName);
	std::cout << "Enter the manager number of trophies: ";
	std::cin >> getnoOfTrophies();
	std::cout << "Enter the manager salary: ";
	std::cin >> getsalary();

	std::string query = "UPDATE managerdb SET MID = '" + std::to_string(managerID) + "', Mfirstname = '" + managerfirstname + "' ,Mlastname = '" + managerlastname + "',Mnationality = '" + nationality + "',Nooftrophies = '" + std::to_string(noOfTrophies) + "',Mteam = '" + teamName + "' ,Msalary = '" + std::to_string(salary) +"' WHERE MID = '"+std::to_string(id)+"')";

	if (mysql_query(db_conn, query.c_str()))
	{
		std::cout << "Failed to create Manager!\n" << mysql_error(db_conn) << std::endl;
	}

	else
		std::cout << "Manager creation successful.\n";
}
 int & Manager::getcount()
{
	return mcount;
}

 void Manager::writecount(int count)
 {
	 std::ofstream StoreCount("ManagerID.txt");
	 StoreCount << getcount();
	 StoreCount.close();
 }
 void Manager::readcount()
 {
	 std::ifstream StoreCount("ManagerID.txt");
	 StoreCount >> getcount();
	 StoreCount.close();
 }