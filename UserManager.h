#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "User.h"
#include "XmlFileWithUsers.h"

using namespace std;

class UserManager
{
    XmlFileWithUsers xmlFileWithUsers;

    int loggedInUserID;
    vector <User> users;

    User enterNewUserData();
    int getNewUserID();

    bool isNick(string nick);

public:

    UserManager(string fileNameUsers, string fileNameIncomes/*, string fileNameExpenses*/)
        : xmlFileWithUsers(fileNameUsers, fileNameIncomes/*, string fileNameExpenses*/)
    {
        loggedInUserID = 0;
        users = xmlFileWithUsers.loadUsersFromFile();
    }

    int getLoggedInUserID();
    void registration();
    void logIn();
    void logOut();
    void changePasswordLoggedInUser();
    void displayAllUsers();
    bool isLogIn();
};




#endif
