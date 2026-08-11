#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "UtilLib.h"

using namespace std;

class clsScreen
{
protected:
    short _ScreenWidth;

    clsScreen(short ScreenWidth = 122)
    {
        _ScreenWidth = ScreenWidth;
    }

    string _GetSystemDateTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[30];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d | %H:%M:%S", ltm);
        return string(buffer);
    }

    void _DrawStatusBar(const string &UserName = "")
    {
        string DateStr = "Date: " + _GetSystemDateTime();
        string UserStr = UserName.empty() ? "" : "User: " + UserName;

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan);
        UtilLib::PrintHeaderLine('=', _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset);

        cout << UtilLib::GetColor(UtilLib::enColor::Yellow);
        cout << left << setw(30) << (" " + DateStr);

        if (!UserStr.empty())
        {
            int Spaces = _ScreenWidth - 30 - (int)UserStr.length() - 1;
            if (Spaces > 0)
                cout << string(Spaces, ' ');
            cout << UserStr;
        }
        cout << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan);
        UtilLib::PrintHeaderLine('-', _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset);
    }

    void _DrawScreenHeader(const string &Title, const string &SubTitle = "", const string &UserName = "")
    {
        _DrawStatusBar(UserName);

        cout << "\n";
        UtilLib::PrintCentered(UtilLib::ColorText(Title, UtilLib::enColor::BrightYellow), _ScreenWidth);

        if (!SubTitle.empty())
        {
            cout << "\n";
            UtilLib::PrintCentered(UtilLib::ColorText(SubTitle, UtilLib::enColor::Yellow), _ScreenWidth);
        }

        cout << "\n\n";
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan);
        UtilLib::PrintHeaderLine('=', _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n\n";
    }

    void _ShowWarningMessage(const string &Message = "WARNING: Invalid Input!")
    {
        cout << "\n";
        UtilLib::PrintCentered("", _ScreenWidth);
        UtilLib::FlashWarningText(Message);
        cout << "\n\n";
    }

    void _ShowLoadingSpinner(const string &Message = "Processing, please wait...", int Cycles = 3)
    {
        UtilLib::ShowSpinner(Message, Cycles);
    }

    void _ShowProgressBar(const string &Message = "Loading data, please wait...")
    {
        UtilLib::ShowProgressBar(Message);
    }

    void _PrintAnimatedSuccess(const string &Text, int SpeedInMs = 20)
    {
        cout << UtilLib::GetColor(UtilLib::enColor::BrightGreen);
        UtilLib::TypeWriterText(Text, SpeedInMs);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
    }

    static void _ResetTheScreen()
    {
        UtilLib::ResetTheScreen();
    }
};