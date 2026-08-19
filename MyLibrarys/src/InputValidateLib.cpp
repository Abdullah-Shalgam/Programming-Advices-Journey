#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <conio.h>
#include "InputValidateLib.h"

using namespace std;

// ─────────────── Int Validations (Redirected to Templates) ───────────────

int InputValidateLib::ReadIntNumber(string Msg, string ErrMsg)
{
    return ReadNumber<int>(Msg, ErrMsg);
}

int InputValidateLib::ReadIntPositiveNumber(string Msg, string ErrMsg)
{
    return ReadPositiveNumber<int>(Msg, ErrMsg);
}

int InputValidateLib::ReadIntNumberInRange(int From, int To, string Msg, string ErrMsg)
{
    return ReadNumberInRange<int>(From, To, Msg, ErrMsg);
}

// ─────────────── Short Validations (Redirected to Templates) ───────────────

short InputValidateLib::ReadShortNumber(string Msg, string ErrMsg)
{
    return ReadNumber<short>(Msg, ErrMsg);
}

short InputValidateLib::ReadShortPositiveNumber(string Msg, string ErrMsg)
{
    return ReadPositiveNumber<short>(Msg, ErrMsg);
}

short InputValidateLib::ReadShortNumberInRange(short From, short To, string Msg, string ErrMsg)
{
    return ReadNumberInRange<short>(From, To, Msg, ErrMsg);
}

// ─────────────── Long Long Validations (Redirected to Templates) ───────────────

long long InputValidateLib::ReadLongLongPositiveNumber(string Msg, string ErrMsg)
{
    return ReadPositiveNumber<long long>(Msg, ErrMsg);
}

// ─────────────── Double Validations (Redirected to Templates) ───────────────

double InputValidateLib::ReadDblNumber(string Msg, string ErrMsg)
{
    return ReadNumber<double>(Msg, ErrMsg);
}

double InputValidateLib::ReadDblPositiveNumber(string Msg, string ErrMsg)
{
    return ReadPositiveNumber<double>(Msg, ErrMsg);
}

double InputValidateLib::ReadDblNumberInRange(double From, double To, string Msg, string ErrMsg)
{
    return ReadNumberInRange<double>(From, To, Msg, ErrMsg);
}

// ─────────────── Text & Character Validations ───────────────

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

string InputValidateLib::ReadLimitedText(short MaxLength, string Msg, string ErrMsg)
{
    while (true)
    {
        string textContent = ReadText(Msg, ErrMsg);
        if (textContent.length() <= static_cast<size_t>(MaxLength))
        {
            return textContent;
        }
        cout << "  [!] Input exceeds maximum allowed length of " << MaxLength << " characters! Please try again.\n\n";
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

// ─────────────── Date Utilities ───────────────

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

// ─────────────── Password / Masked Text Utilities ───────────────

string InputValidateLib::ReadPassword(string Msg, short MinLength, string ErrMsg)
{
    string password = "";
    char ch;

    while (true)
    {
        password = "";
        cout << Msg;

        while (true)
        {
            ch = _getch();

            if (ch == 13)
            {
                cout << endl;
                break;
            }
            else if (ch == 8)
            {
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch == 0 || ch == -32)
            {
                _getch();
            }
            else if (isprint(static_cast<unsigned char>(ch)))
            {
                password += ch;
                cout << '*';
            }
        }

        if (password.length() < MinLength)
        {
            cout << "  [!] Security Warning: Password must be at least " << MinLength << " characters long!\n\n";
            continue;
        }

        return password;
    }
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