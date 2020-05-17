#include <iostream>
#include "WalletManager.h"

using namespace std;

int main()
{


    WalletManager walletManager("users.xml", "incomes.xml", "expenses.xml");

    //walletManager.registration();
    walletManager.displayAllUsers();
    walletManager.logIn();
    //walletManager.displayAllIncomes1();
    //walletManager.addIncome();
    //walletManager.addExpense();
    //walletManager.displayAllIncome();
    walletManager.displayIncomesCurrentMonth();
    walletManager.displayExpensesCurrentMonth();
    //walletManager.displayIncomesPreviousMonth();
    //walletManager.displayIncomesPeriodTime();
    //walletManager.changePasswordLoggedInUser();
    walletManager.displayIncomesSum();
    walletManager.displayExpensesSum();
    walletManager.displayIncomesExpensesSum();
    walletManager.logOut();

    return 0;
}
