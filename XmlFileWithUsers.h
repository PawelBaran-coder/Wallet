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
public:

    XmlFileWithUsers(string fileNameUsers, string fileNameIncomes, string fileNameExpenses)
        : XmlFile(fileNameUsers, fileNameIncomes, fileNameExpenses)
    {}

    void addUserToFile(User user);
    void addAllUsersToFile(vector <User> &users);
    vector <User> loadUsersFromFile();

};
#endif
