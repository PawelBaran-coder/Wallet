#include <iostream>
#include "WalletManager.h"

using namespace std;

int main()
{


    WalletManager walletManager("uzytkownicy.xml");

    walletManager.registration();
    walletManager.displayAllUsers();

    cout << "Hello world!" << endl;
    return 0;
}
