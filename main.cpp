#include <iostream>
#include "WalletManager.h"

using namespace std;

int main()
{


    WalletManager walletManager("users.xml");

    walletManager.registration();
    walletManager.displayAllUsers();

    return 0;
}
