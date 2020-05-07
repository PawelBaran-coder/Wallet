#ifndef XMLFILEINCOMES_H
#define XMLFILEINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "AdditionalMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class XmlFileIncomes : public XmlFile
{
    int lastIncomeID;

    int getLastIncomeIdFromFile();
/*
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzZPlikuIdOstatniegoAdresata();
    void usunPlik(string NAZWA_PLIKU_Z_ADRESATAMI);
    void zmienNazwePliku(string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, string NAZWA_PLIKU_Z_ADRESATAMI);
*/
public:
    XmlFileIncomes(string fileNameUsers, string fileNameIncomes/*, string fileNameExpenses*/)
        : XmlFile(fileNameUsers, fileNameIncomes/*, fileNameExpenses*/)
    {
        lastIncomeID = 0;
    }

    //int getLastIncomeId();
    void addIncomeToFile(Income income);

    vector <Income> loadIncomesFromFile(int loggedInUserId);
    /*
    bool dopiszAdresataDoPliku(Adresat adresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void edytujAdresataWPliku(Adresat adresat, int idEdytowanegoAdresata);
    */
};
#endif
