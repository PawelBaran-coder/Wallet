#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

class WalletManager
{
    UserManager userManager;
   // BalanceSheet *balanceSheet;

   const string FILE_NAME_USERS;
   //const string FILE_NAME_INCOMES;
   //const string FILE_NAME_EXPENSES;

public:

WalletManager(string fileNameUsers/*, string fileNameIncomes, string fileNameExpenses*/)
        : userManager(fileNameUsers/*, fileNameIncomes, fileNameExpenses*/) /*,FILE_NAME_INCOMES(fileNameIncomes), FILE_NAME_EXPENSES(fileNameExpenses)*/
    {
        // BalanceSheet = NULL;
    }
   /* ~WalletManager()
    {
        delete BalanceSheet;
        BalanceSheet = NULL;
    }
*/
    void registration();
    void displayAllUsers();
    void logIn();
    void logOut();
    void changePasswordLoggedInUser();
    bool isLogIn();


};


#endif
