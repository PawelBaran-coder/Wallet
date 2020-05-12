#include <iostream>
#include "WalletManager.h"

using namespace std;

int main()
{


    WalletManager walletManager("users.xml", "incomes.xml");

    //walletManager.registration();
    walletManager.displayAllUsers();
    walletManager.logIn();
    //walletManager.displayAllIncomes1();
    //walletManager.addIncome();
    //walletManager.displayAllIncome();
    walletManager.sortIncomeDate();
    //walletManager.changePasswordLoggedInUser();
    walletManager.logOut();

    return 0;
}
