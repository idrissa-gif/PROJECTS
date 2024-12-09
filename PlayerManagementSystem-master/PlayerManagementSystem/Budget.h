#pragma once
class Budget
{
private:
	double transfer_budget;
	double salary_budget;
public:
	double get_transfer_budget();
	void set_transfer_budget(double transfer_budget);
	double getsalary_budget();
	void setsalary_budget(double salary_budget);
};

