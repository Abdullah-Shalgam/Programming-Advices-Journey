#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:
    // -------------------------------------------------------------
    // Template Functions
    // -------------------------------------------------------------
    template <typename T>
    static bool IsNumberBetween(T Num, T From, T To)
    {
        return (Num >= From && Num <= To);
    }

    // -------------------------------------------------------------
    // Date Functions
    // -------------------------------------------------------------
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        if (clsDate::IsDate1BeforeDate2(To, From))
        {
            clsDate::SwapDates(From, To);
        }

        return !(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1AfterDate2(Date, To));
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    // -------------------------------------------------------------
    // Integer Reading & Validation
    // -------------------------------------------------------------
    static int ReadIntNumber(string Msg = "Please enter a number: ", string ErrMsg = "Invalid Number, Enter again: ")
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

    static int ReadIntPositiveNumber(string Msg = "Please enter a positive number: ", string ErrMsg = "Invalid Positive Number, Enter again: ")
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

    static int ReadIntNumberInRange(int From, int To, string Msg = "Please enter a number in range: ", string ErrMsg = "Number is not within range, Enter again: ")
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

    static long long ReadLongLongPositiveNumber(string Msg = "Please enter a positive number: ", string ErrMsg = "Invalid Positive Number, Enter again: ")
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

    // -------------------------------------------------------------
    // Double Reading & Validation
    // -------------------------------------------------------------
    static double ReadDblNumber(string Msg = "Please enter a double number: ", string ErrMsg = "Invalid Number, Enter again: ")
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

    static double ReadDblPositiveNumber(string Msg = "Please enter a positive double number: ", string ErrMsg = "Invalid Positive Number, Enter again: ")
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

    static double ReadDblNumberInRange(double From, double To, string Msg = "Please enter a double number in range: ", string ErrMsg = "Number is not within range, Enter again: ")
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

    // -------------------------------------------------------------
    // String & Character Reading
    // -------------------------------------------------------------
    static string ReadText(string Msg = "Please enter text: ", string ErrMsg = "Invalid Input, Enter again: ")
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

    static char ReadCharacter(string Msg = "Please enter a character: ", string ErrMsg = "Invalid Character, Enter again: ")
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

    static char getYesNoAnswer(string Msg = "Please enter (Y/N): ", string ErrMsg = "Invalid Answer! Please enter (Y/N): ")
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
};