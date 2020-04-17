#include "KsiazkaAdresowa.h"

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

        //adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_UZYTKOWNIKAMI, NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());

}

void WalletManager::logout()
{
    userManager.logout();
    //delete adresatMenadzer;
    // adresatMenadzer = NULL;
}

void WalletManager::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

bool WalletManager::isLogIn()
{
    userManager.isLogIn();
}
