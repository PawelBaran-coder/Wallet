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
    balanceSheet = new BalanceSheet(FILE_NAME_USERS, FILE_NAME_INCOMES, FILE_NAME_EXPENSES, userManager.getLoggedInUserID());
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

void WalletManager::addExpense()
{
    if(userManager.isLogIn())
    {
        balanceSheet->addExpense();
    }
    else
    {
        cout << "Aby dodac koszt, musisz byc zalogowany" << endl;
        system("pause");
    }
}

void WalletManager::balanceCurrentMonth()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayIncomesCurrentMonth();
        balanceSheet->displayExpensesCurrentMonth();
        balanceSheet->displayIncomesSum();
        balanceSheet->displayExpensesSum();
        balanceSheet->displayIncomesExpensesSum();
        system("pause");
    }
    else
    {
        cout << "Aby wyswietlic bilans z biezacego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
}

 void WalletManager::balancePreviousMonth()
 {
     if(userManager.isLogIn())
    {
        balanceSheet->displayIncomesPreviousMonth();
        balanceSheet->displayExpensesPreviousMonth();
        balanceSheet->displayIncomesSum();
        balanceSheet->displayExpensesSum();
        balanceSheet->displayIncomesExpensesSum();
        system("pause");
    }
    else
    {
        cout << "Aby wyswietlic bilans z poprzedniego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
 }

void WalletManager::balancePeriodTime()
{
     if(userManager.isLogIn())
    {
        balanceSheet->setPeriodTime();
        balanceSheet->displayIncomesPeriodTime();
        balanceSheet->displayExpensesPeriodTime();
        balanceSheet->displayIncomesSum();
        balanceSheet->displayExpensesSum();
        balanceSheet->displayIncomesExpensesSum();
        system("pause");
    }
    else
    {
        cout << "Aby wyswietlic bilans w zadanym okresie, musisz byc zalogowany" << endl;
        system("pause");
    }
}










void WalletManager::displayAllIncomesItr()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayAllIncomesItr();
    }
    else
    {
        cout << "Aby dodac przychod, musisz byc zalogowany" << endl;
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
//-----------------------------EXPENSES----------------------------------


void WalletManager::displayAllExpensesItr()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayAllExpensesItr();
    }
    else
    {
        cout << "Aby dodac koszt, musisz byc zalogowany" << endl;
        system("pause");
    }
}

void WalletManager::displayExpensesCurrentMonth()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayExpensesCurrentMonth();
    }
    else
    {
        cout << "Aby wyswietlic wydatki biezacego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayExpensesPreviousMonth()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayExpensesPreviousMonth();
    }
    else
    {
        cout << "Aby wyswietlic wydatki poprzedniego miesiaca, musisz byc zalogowany" << endl;
        system("pause");
    }
}
void WalletManager::displayExpensesPeriodTime()
{
    if(userManager.isLogIn())
    {
        balanceSheet->displayExpensesPeriodTime();
    }
    else
    {
        cout << "Aby wyswietlic wydatki z zadanego okresu, musisz byc zalogowany" << endl;
        system("pause");
    }
}
//-----------------------------------------------------------------------

    void WalletManager::displayIncomesSum()
    {
        balanceSheet->displayIncomesSum();
    }
    void WalletManager::displayExpensesSum()
    {
        balanceSheet->displayExpensesSum();
    }
    void WalletManager::displayIncomesExpensesSum()
    {
        balanceSheet->displayIncomesExpensesSum();
    }
