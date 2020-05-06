#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class AdditionalMethods
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
    static char wczytajZnak();

    static string loadLine();
    static bool isDateCorrect();
    static float correctAmount(string amount);
    static int convertStringDateToIntegerDate(string dateStringDash);
    static string convertIntegerDateToStringDate();
};
#endif
