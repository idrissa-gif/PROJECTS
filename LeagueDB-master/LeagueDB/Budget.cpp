#include "Budget.h"

double & Budget::getsalaryBudget()
{
    return salaryBudget;
}

double & Budget::gettransferBudget()
{
    return transferBudget;
}

void Budget::setsalaryBudget(double value)
{
    salaryBudget = value;
}

void Budget::settransferBudget(double value)
{
    transferBudget = value;
}
