#include "XmlFileWithUsers.h"
#include <cstdlib>

string XmlFileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += AdditionalMethods::konwerjsaIntNaString(user.getId())+ '|';
    liniaZDanymiUzytkownika += user.getNick() + '|';
    liniaZDanymiUzytkownika += user.getPassword() + '|';

    return liniaZDanymiUzytkownika;
}

vector <User> XmlFileWithUsers::wczytajUzytkownikowZPliku()
{
    User user;
    vector <User> users;
    fstream xmlFile;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    xmlFile.open(getFileName().c_str(), ios::in);

    if (xmlFile.good() == true)
    {
        while (getline(xmlFile, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            user = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            users.push_back(user);
        }
        xmlFile.close();
    }
    return users;
}

User XmlFileWithUsers::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    User user;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                user.setId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                user.setNick(pojedynczaDanaUzytkownika);
                break;
            case 3:
                user.setPassword(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return user;
}

//---------------------------------------------
void XmlFileWithUsers::addUserToFile(User user)
{

    int userId = user.getId();
    string name = user.getName();
    string lastName = user.getLastName();
    string nick = user.getNick();
    string password = user.getPassword();

    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", userId);
    xml.AddElem("name", name);
    xml.AddElem("lastName", lastName);
    xml.AddElem("nick", lastName);
    xml.AddElem("password", password);

    xml.Save(getFileName().c_str());

}

