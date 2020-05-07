#include "AdditionalMethods.h"

string AdditionalMethods::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AdditionalMethods::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string AdditionalMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int AdditionalMethods::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string AdditionalMethods::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int AdditionalMethods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

char AdditionalMethods::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
//--------------------------------------------------------
string AdditionalMethods::loadLine()
{
    string lineIn = "";
    getline(cin, lineIn);
    return lineIn;
}
int AdditionalMethods::convertStringDateToIntegerDate(string dateStringDash)
{
    string dateStringNotDash = "";
    string dateElement ="";
    int dateInt = 0;

    char separator = '-';

    stringstream ss(dateStringDash);

    while (getline(ss, dateElement, separator))
    {
        dateStringNotDash += dateElement;
    }

    dateInt = atoi(dateStringNotDash.c_str());

    return dateInt;
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
    //cout << "twoja liczba jako float: " << liczbaFloat << endl;

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
