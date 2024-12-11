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
	Manager(string name, int age, double salary, int contract_period,int no_trophies):name(name),age(age),salary(salary),contract_period(contract_period),no_trophies(no_trophies)
	{

	}
};

