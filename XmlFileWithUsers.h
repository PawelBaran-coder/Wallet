#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AdditionalMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class XmlFileWithUsers : public XmlFile
{
    //string replaceUserDataWithDataLineDividedByVerticalDashes();
    //User getUserData();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
    User pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:

    XmlFileWithUsers(string fileNameUsers/*, string fileNameIncomes, string fileNameExpenses*/)
        : XmlFile(fileNameUsers/*, fileNameIncomes, fileNameExpenses*/)
    {}

    void addUserToFile(User user);
    void zapiszWszystkichUzytkownikowDoPliku(vector <User> &users);
    //void addAllUsersToFile(vector <User> &users);
    vector <User> wczytajUzytkownikowZPliku();
    //vector <User> loadUsersFromFile();

};
#endif
