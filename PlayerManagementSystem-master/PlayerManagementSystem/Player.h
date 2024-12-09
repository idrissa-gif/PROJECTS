#pragma once
#include<iostream>

using namespace std;
class Player
{
private:
	string name;
	int age;
	double salary;
	int contract_period;
	double value;
	double rating;
	string position;
public:
	Player() :name(""), age(0), salary(0), contract_period(0), value(0), rating(0), position("")
	{}
	~Player(){}
	string getname();
	int getage();
	double getvalue();
	double getrating();
	string getposition();

	void setname(string name);
	void setage(int age);
	void setvalue(double value);
	void setrating(double);
	void setposition(string position);
};

