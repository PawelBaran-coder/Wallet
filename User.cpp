#include "User.h"

void User::setId(int newId)
{
    if(newId >= 0)
        userId = newId;
}
void User::setName(string newName)
{
    name = newName;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}
int User::getId()
{
    return userId;
}
string User::getName()
{
    return name;
}
string User::getPassword()
{
    return password;
}
