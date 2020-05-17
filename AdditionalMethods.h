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
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();

    static string loadLine();
    static char loadChar();
    static bool isDateCorrect();
    static float correctAmount(string amount);
    static string convertFloatToString(float amount);
    static float convertStringToFloat(string amount);
    static string convertIntegerToString(int integerNumber);
    static int convertStringToInteger(string stringNumber);
};
#endif
