#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <conio.h>
#include "InputValidateLib.h"

using namespace std;

int InputValidateLib::ReadIntNumber(string Msg, string ErrMsg)
{
    string inputLine;
    long validatedNumber;
    cout << Msg;
    while (true)
    {
        if (!getline(cin >> ws, inputLine))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrMsg << "\n";
            cout << Msg;
            continue;
        }
        char* processedCharactersEnd;
        validatedNumber = strtol(inputLine.c_str(), &processedCharactersEnd, 10);
        if (processedCharactersEnd != inputLine.c_str() && *processedCharactersEnd == '\0')
        {
            return static_cast<int>(validatedNumber);
        }
        cout << ErrMsg << "\n";
        cout << Msg;
    }
}

double InputValidateLib::ReadDblNumber(string Msg, string ErrMsg)
{
    string inputLine;
    double validatedNumber;
    cout << Msg;
    while (true)
    {
        if (!getline(cin >> ws, inputLine))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrMsg << "\n";
            cout << Msg;
            continue;
        }
        char* processedCharactersEnd;
        validatedNumber = strtof(inputLine.c_str(), &processedCharactersEnd);
        if (processedCharactersEnd != inputLine.c_str() && *processedCharactersEnd == '\0')
        {
            return validatedNumber;
        }
        cout << ErrMsg << "\n";
        cout << Msg;
    }
}

int InputValidateLib::ReadIntPositiveNumber(string Msg, string ErrMsg)
{
    while (true)
    {
        int Number = ReadIntNumber(Msg, ErrMsg);
        if (Number >= 0)
        {
            return Number;
        }
        cout << ErrMsg << "\n";
    }
}

long long InputValidateLib::ReadLongLongPositiveNumber(string Msg, string ErrMsg)
{
    string inputLine;
    cout << Msg;
    while (true)
    {
        if (!getline(cin >> ws, inputLine))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrMsg << "\n";
            cout << Msg;
            continue;
        }
        char* processedCharactersEnd;
        errno = 0;
        long long validatedNumber = strtoll(inputLine.c_str(), &processedCharactersEnd, 10);
        if (processedCharactersEnd != inputLine.c_str() && 
            *processedCharactersEnd == '\0' && 
            errno != ERANGE && 
            validatedNumber >= 0)
        {
            return validatedNumber;
        }
        cout << ErrMsg << "\n";
        cout << Msg;
    }
}

double InputValidateLib::ReadDblPositiveNumber(string Msg, string ErrMsg)
{
    while (true)
    {
        double Number = ReadDblNumber(Msg, ErrMsg);
        if (Number >= 0.0)
        {
            return Number;
        }
        cout << ErrMsg << "\n";
    }
}

int InputValidateLib::ReadIntNumberInRange(int From, int To, string Msg, string ErrMsg)
{
    while (true)
    {
        int Number = ReadIntNumber(Msg, ErrMsg);
        if (IsNumberBetween(Number, From, To))
        {
            return Number;
        }
        cout << ErrMsg << "\n";
    }
}

double InputValidateLib::ReadDblNumberInRange(double From, double To, string Msg, string ErrMsg)
{
    while (true)
    {
        double Number = ReadDblNumber(Msg, ErrMsg);
        if (IsNumberBetween(Number, From, To))
        {
            return Number;
        }
        cout << ErrMsg << "\n";
    }
}

string InputValidateLib::ReadText(string Msg, string ErrMsg)
{
    string textContent;
    cout << Msg;
    while (true)
    {
        if (getline(cin >> ws, textContent))
        {
            return textContent;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ErrMsg << "\n";
        cout << Msg;
    }
}

char InputValidateLib::ReadCharacter(string Msg, string ErrMsg)
{
    string inputLine;
    cout << Msg;
    while (true)
    {
        if (!getline(cin >> ws, inputLine))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrMsg << "\n";
            cout << Msg;
            continue;
        }
        if (inputLine.length() == 1)
        {
            return inputLine[0];
        }
        cout << ErrMsg << "\n";
        cout << Msg;
    }
}

char InputValidateLib::getYesNoAnswer(string Msg, string ErrMsg)
{
    while (true)
    {
        char ch = ReadCharacter(Msg, ErrMsg);
        char targetChar = tolower(static_cast<unsigned char>(ch));
        if (targetChar == 'y' || targetChar == 'n')
        {
            return targetChar;
        }
        cout << ErrMsg << "\n";
    }
}

bool InputValidateLib::IsDateBetween(DateLib Date, DateLib From, DateLib To)
{
    if (DateLib::IsDate1BeforeDate2(To, From))
    {
        DateLib::SwapDates(From, To);
    }

    return !(DateLib::IsDate1BeforeDate2(Date, From) || DateLib::IsDate1AfterDate2(Date, To));
}

bool InputValidateLib::IsValideDate(DateLib Date)
{
    return DateLib::IsValidDate(Date);
}

string InputValidateLib::_ReadPinMasked(string Msg)
{
    string pin = "";
    char ch;
    cout << Msg;
    while (true)
    {
        ch = _getch();
        if (ch == 13) 
        {
            if (!pin.empty()) 
                break;
        }
        else if (ch == 8) 
        {
            if (!pin.empty())
            {
                pin.pop_back();
                cout << "\b \b";
            }
        }
        else if (isdigit(ch) && pin.length() < 4)
        {
            pin += ch;
            cout << '*';
        }
    }
    cout << endl;
    return pin;
}

string InputValidateLib::GetValidPIN(string Msg, string ErrMsg)
{
    string pin;
    while (true)
    {
        pin = _ReadPinMasked(Msg);
        if (pin.length() != 4)
        {
            cout << ErrMsg;
            continue;
        }
        return pin;
    }
}