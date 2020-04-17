#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "User.h"
//#include "PlikZUzytkownikami.h"

using namespace std;

class UserManager
{
    //PlikZUzytkownikami plikZUzytkownikami;

    int loggedInUserID;
    vector <User> users;

    User enterNewUserData();
    int getNewUserID();
    bool isName(string name);

public:
    /*
    UzytkownikMenadzer(string nazwaPliku, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami)
        : plikZUzytkownikami(nazwaPliku, nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    }
    */
    void registration();
    void logIn();
    void logout();
    void changePasswordLoggedInUser();
    void displayAllUsers();
    bool isLogIn();
    int getLoggedInUserID();
};




#endif
