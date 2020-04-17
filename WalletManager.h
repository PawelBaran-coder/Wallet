#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

class WalletManager
{
    UserManager userManager;
   // AdresatMenadzer *adresatMenadzer;
   // const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
   // const string NAZWA_PLIKU_Z_ADRESATAMI;
   // const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;


public:
/*
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami, nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami)
    {
        adresatMenadzer = NULL;
    }
    ~KsiazkaAdresowa()
    {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    }
*/
    void registration();
    void displayAllUsers();
    void logIn();
    void logout();
    void changePasswordLoggedInUser();
    bool isLogIn();


};


#endif
