#include <iostream>
#include "WalletManager.h"

using namespace std;

int main()
{


    WalletManager walletManager("users.xml");

    walletManager.registration();
    walletManager.displayAllUsers();
    walletManager.logIn();
    walletManager.changePasswordLoggedInUser();
    //walletManager.logOut();

    return 0;
}
