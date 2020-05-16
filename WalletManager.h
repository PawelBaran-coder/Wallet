#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <iostream>
#include <windows.h>
#include "UserManager.h"
#include "BalanceSheet.h"

using namespace std;

class WalletManager
{
    UserManager userManager;
    BalanceSheet *balanceSheet;

   const string FILE_NAME_USERS;
   const string FILE_NAME_INCOMES;
   const string FILE_NAME_EXPENSES;

public:

WalletManager(string fileNameUsers, string fileNameIncomes, string fileNameExpenses)
        : userManager(fileNameUsers, fileNameIncomes, fileNameExpenses), FILE_NAME_INCOMES(fileNameIncomes), FILE_NAME_EXPENSES(fileNameExpenses)
    {
        balanceSheet = NULL;
    }
    ~WalletManager()
    {
        delete balanceSheet;
        balanceSheet = NULL;
    }

    void registration();
    void displayAllUsers();
    void logIn();
    void logOut();
    void changePasswordLoggedInUser();
    bool isLogIn();

    void addIncome();

    void displayAllIncome();
    void displayAllIncomes1();
    void displayIncomesCurrentMonth();
    void displayIncomesPreviousMonth();
    void displayIncomesPeriodTime();
};


#endif
