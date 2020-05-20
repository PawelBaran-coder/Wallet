#ifndef XMLFILEINCOMES_H
#define XMLFILEINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "AdditionalMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class XmlFileIncomes : public XmlFile
{
    int lastIncomeID;

    int getLastIncomeIdFromFile();

public:
    XmlFileIncomes(string fileNameUsers, string fileNameIncomes, string fileNameExpenses)
        : XmlFile(fileNameUsers, fileNameIncomes, fileNameExpenses)
    {
        lastIncomeID = 0;
    }
    //int getLastIncomeId();
    void addIncomeToFile(Income income);

    vector <Income> loadIncomesFromFile(int loggedInUserId);

};
#endif
