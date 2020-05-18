#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "XmlFileIncomes.h"
#include "XmlFileExpenses.h"
#include "CurrentDate.h"
#include "Date.h"

using namespace std;

class BalanceSheet
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    Date date;
    XmlFileIncomes xmlFileIncomes;
    XmlFileExpenses xmlFileExpenses;
    float sumIncomes;
    float sumExpenses;



    Income enterNewIncomeData();
    int getIncomeNewId();
    Expense enterNewExpenseData();
    int getExpenseNewId();

public:

    BalanceSheet(string fileNameUsers, string fileNameIncomes, string fileNameExpenses, int loggedInUserID)
        :xmlFileIncomes(fileNameUsers,fileNameIncomes, fileNameExpenses),
         xmlFileExpenses(fileNameUsers,fileNameIncomes, fileNameExpenses), LOGGED_IN_USER_ID(loggedInUserID)
    {
        expenses = xmlFileExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
        incomes = xmlFileIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        sort( incomes.begin(), incomes.end() );
        sort( expenses.begin(), expenses.end() );

    }

    void addIncome();
    void addExpense();

    void displayIncome(Income income);// do usuniecia
     void displayExpense(Expense expense); // do usuniecia

    void displayIncomesCurrentMonth();
    void displayIncomesPreviousMonth();
    void displayIncomesPeriodTime();

    void displayExpensesCurrentMonth();
    void displayExpensesPreviousMonth();
    void displayExpensesPeriodTime();

    void displayIncomesSum();
    void displayExpensesSum();
    void displayIncomesExpensesSum();

    void setPeriodTime();



};


#endif
