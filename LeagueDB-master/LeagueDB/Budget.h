#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif

class Budget
{
private:
	double transferBudget;
	double salaryBudget;
public:
	double & getsalaryBudget();
	double & gettransferBudget();
    void setsalaryBudget(double value);
	void settransferBudget(double value);
};

