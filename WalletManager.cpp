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
   if (userManager.isLogIn())
    balanceSheet = new BalanceSheet(FILE_NAME_USERS, FILE_NAME_INCOMES, /*FILE_NAME_EXPENSES,*/ userManager.getLoggedInUserID());
}

void WalletManager::logOut()
{
    userManager.logOut();
    delete balanceSheet;
    balanceSheet = NULL;
}

void WalletManager::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

bool WalletManager::isLogIn()
{
    userManager.isLogIn();
}

void WalletManager::addIncome()
{
    if(userManager.isLogIn())
    {
        balanceSheet->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, musisz byc zalogowany" << endl;
        system("pause");
    }
}

void WalletManager::displayAllIncome()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayAllIncome();
    }
    else
    {
        cout << "Aby dodac przychod, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayAllIncomes1()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayAllIncomes1();
    }
    else
    {
        cout << "Aby dodac przychod, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::sortIncomeDate()
{
    if(userManager.isLogIn())
    {
        balanceSheet->sortIncome();
    }
    else
    {
        cout << "Aby sortowac przychody, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayIncomesCurrentMonth()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayIncomesCurrentMonth();
    }
    else
    {
        cout << "Aby wyswietlic przychody biezacego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayIncomesPreviousMonth()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayIncomesPreviousMonth();
    }
    else
    {
        cout << "Aby wyswietlic przychody poprzedniego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayIncomesPeriodTime()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayIncomesPeriodTime();
    }
    else
    {
        cout << "Aby wyswietlic przychody z zadanego okresu, musisz byc zalogowany" << endl;
        system("pause");
    }
}
