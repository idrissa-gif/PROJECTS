#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif
#ifndef __MYSQL_H
#include<mysql.h>
#define MYSQL_H
#endif

class Player
{
protected:
    MYSQL* db_conn;
    int pcount;
    std::string playerFirstname;
    std::string playerLastname;
    int playerID;
    int age;
    float weight;
    float height;
    int rating;
    std::string nationality;
    std::string position;
    enum dom_leg { left, right };
    double marketValue;
    double annualSalary;
public:

    Player(const  std::string = "localhost", const std::string = "", const std::string = "", const std::string = "");
    virtual ~Player();
    std::string& getplayerfirstname();
    std::string& getplayerlastname();
    int& getplayerID();
    int& getplayerage();
    float& getweight();
    int& getcount();
    float& getheight();
    int& getrating();
    std::string& getnationality();
    std::string getdominantleg(int dl);
    double& getmarketvalue();
    double& getannaualsalary();
    virtual void insert(std::string);
    void deleteplayer(int id);
    void searchplayer(int id);
    void printall();
    void editplayer(int id);
    void writecount(int );
    void readcount();
};

