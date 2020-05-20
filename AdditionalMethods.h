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

    static string loadLine();
    static char loadChar();
    static string getNumber(string text, int charPosition);
    static float correctAmount(string amount);
    static string convertFloatToString(float amount);
    static float convertStringToFloat(string amount);
    static string convertIntegerToString(int integerNumber);
    static int convertStringToInteger(string stringNumber);
};
#endif
