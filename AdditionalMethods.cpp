#include "AdditionalMethods.h"

string AdditionalMethods::loadLine()
{
    string lineIn = "";
    getline(cin, lineIn);
    return lineIn;
}
char AdditionalMethods::loadChar()
{
    string input = "";
    char character = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

float AdditionalMethods::correctAmount(string amount)
{
    stringstream ss;

    float amountFloat = 0;

    for (int i = 0 ; i <= amount.length() ; i ++ )
    {
        if (amount[i] == ',')
        {
            amount[i] = '.';
        }
    }
    ss << amount;
    ss >> amountFloat;

    return amountFloat;
}

string AdditionalMethods::convertFloatToString(float amount)
{
    stringstream FloatToStr;
    string stringAmount;

    FloatToStr << amount;
    FloatToStr >> stringAmount;

    return stringAmount;
}
float AdditionalMethods::convertStringToFloat(string amount)
{
    stringstream stringToFloat;
    float floatAmount;

    stringToFloat << amount;
    stringToFloat >> floatAmount;

    return floatAmount;
}
string AdditionalMethods::convertIntegerToString(int integerNumber)
{
    ostringstream integerToString;
    integerToString << integerNumber;
    string stringNumber = integerToString.str();
    return stringNumber;
}

int AdditionalMethods::convertStringToInteger(string stringNumber)
{
    int integerNumber;
    istringstream stringToInteger(stringNumber);
    stringToInteger >> integerNumber;

    return integerNumber;
}
string AdditionalMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}
