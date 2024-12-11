#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
class Manager
{
private:
    MYSQL* db_conn;
    int mcount;
    std::string managerfirstname;
    std::string managerlastname;
    std::string nationality;
    int managerID;
    int noOfTrophies;
    double salary;
public:
    Manager(const  std::string = "localhost", const std::string = "", const std::string = "", const std::string = "");
    ~Manager();
    int& getcount();
    int& getmanagerID();
    std::string& getmanagerfirstName();
    std::string& getmanagerlastName();
    std::string& getmanagerNationality();
    double& getsalary();
    int& getnoOfTrophies();
    void printall();
    void deleteteam(int id);
    void insert();
    void search(int id);
    void edit(int id);
    void writecount(int);
    void readcount();
};

