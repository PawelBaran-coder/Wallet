#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    if(newExpenseId >= 0)
        expenseId = newExpenseId;
}
void Expense::setExpenseAmount(float newExpenseAmount)
{
    if(newExpenseAmount >= 0)
        expenseAmount = newExpenseAmount;
}
void Expense::setDescription(string newDescription)
{
    description = newDescription;
}

int Expense::getExpenseId()
{
    return expenseId;
}
float Expense::getExpenseAmount()
{
    return expenseAmount;
}
string Expense::getDescription()
{
    return description;
}
