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

    bool isLogIn();

    void addIncome();
    void addExpense();
    void balanceCurrentMonth();
    void balancePreviousMonth();
    void balancePeriodTime();
    void logOut();
    void changePasswordLoggedInUser();
    //--------------------------------------------

    void displayAllIncomesItr();
    void displayIncomesCurrentMonth();
    void displayIncomesPreviousMonth();
    void displayIncomesPeriodTime();


    void displayAllExpensesItr();
    void displayAllExpenses();
    void displayExpensesCurrentMonth();
    void displayExpensesPreviousMonth();
    void displayExpensesPeriodTime();

    void displayIncomesSum();
    void displayExpensesSum();
    void displayIncomesExpensesSum();

};


#endif
