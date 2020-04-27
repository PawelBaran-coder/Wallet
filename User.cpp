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
void User::setLastName(string newLastName)
{
    lastName = newLastName;
}
void User::setNick(string newNick)
{
    nick = newNick;
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
string User::getLastName()
{
    return lastName;
}
string User::getNick()
{
    return nick;
}
string User::getPassword()
{
    return password;
}
