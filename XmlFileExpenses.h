#ifndef XMLFILEEXPENSES_H
#define XMLFILEEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "AdditionalMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class XmlFileExpenses : public XmlFile
{
    int lastExpenseID;

    int getLastExpenseIdFromFile();

public:
    XmlFileExpenses(string fileNameUsers, string fileNameIncomes, string fileNameExpenses)
        : XmlFile(fileNameUsers, fileNameIncomes, fileNameExpenses)
    {
        lastExpenseID = 0;
    }
    //int getLastIncomeId();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);
};
#endif
