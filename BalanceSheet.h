#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>
#include<cstdlib>
#include<iomanip>
#include<algorithm>

#include "Income.h"
//#include "Expense.h"
#include "XmlFileIncomes.h"
//#include "XmlFileExpenses.h"
#include "CurrentDate.h"
#include "Date.h"

using namespace std;

class BalanceSheet
{
    const int LOGGED_IN_USER_ID;
    XmlFileIncomes xmlFileIncomes;
    vector <Income> incomes;
    // vector <Expense> expenses;

    //TRZEBA BEDZIE ZROBIC XMLFILEEXPENSES JAKO WSKAZNIK
//    XmlFileExpenses xmlFileExpenses;
    //Data data;
    //CurrentDate currentDate;
    //char answer;
    //float accountBalance;
    Income enterNewIncomeData();
    int getNewIncomeId();

    /*
    Adresat podajDaneNowegoAdresata();
    int podajIdWybranegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    char wybierzOpcjeZMenuEdycja();
    */

public:

    BalanceSheet(string fileNameUsers, string fileNameIncomes, /*string fileNameExpenses,*/ int loggedInUserID)
        :xmlFileIncomes(fileNameUsers,fileNameIncomes/*, fileNameExpenses*/), LOGGED_IN_USER_ID(loggedInUserID)
    {

        //incomes = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        incomes = xmlFileIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        sort( incomes.begin(), incomes.end() );
    }

    void addIncome();
    void addExpense();
    void displayIncome(Income income);
    void displayAllIncome();
    void displayAllIncomes1();
    void sortIncome();
    void displayIncomesCurrentMonth();
    void displayIncomesPreviousMonth();
    void displayIncomesPeriodTime();
};


#endif
