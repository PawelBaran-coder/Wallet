#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>


using namespace std;

class XmlFile
{
    const string FILE_NAME_USERS;
    const string FILE_NAME_INCOMES;
    //const string FILE_NAME_EXPENSES;

public:

    XmlFile(string fileName, string fileNameIncomes/*, string fileNameExpenses*/)
        : FILE_NAME_USERS(fileName), FILE_NAME_INCOMES(fileNameIncomes)/*, FILE_NAME_EXPENSES(fileNameExpenses)*/
    {}

    string getFileName();
    string getIncomesFileName();
    string getExpensesFileName();
    //bool isEmpty();

};
#endif
