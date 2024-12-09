#pragma once
#include<iostream>
using namespace std;
class Manager
{
private:
	string name;
	int age;
	double salary;
	int contract_period;
	int no_trophies;
public:
	string getname();
	int getage();
	double getsalary();
	int getcontract_period();
	int getno_trophies();

	void setname(string name);
	void setage(int age);
	void setsalary(double salary);
	void setcontract_period(int contract_period);
	void setno_trophies(int no_trop);
};

