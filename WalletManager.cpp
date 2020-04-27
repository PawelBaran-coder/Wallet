#include "WalletManager.h"

void WalletManager::registration()
{
    userManager.registration();
}

void WalletManager::displayAllUsers()
{
    userManager.displayAllUsers();
}

void WalletManager::logIn()
{
    userManager.logIn();
   // if (userManager.isLogIn())

        //balanceSheet = new BalanceSheet(FILE_NAME_USERS, FILE_NAME_INCOMES, FILE_NAME_EXPENSES, userManager.getLoggedInUserID());

}

void WalletManager::logOut()
{
    userManager.logOut();
    //delete balanceSheet;
    // balanceSheet = NULL;
}

void WalletManager::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

bool WalletManager::isLogIn()
{
    userManager.isLogIn();
}
