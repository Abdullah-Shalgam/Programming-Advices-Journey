#pragma once

#include "Global.h"

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <conio.h>

#include "clsUser.h"
#include "InputValidateLib.h"
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

    void _DrawStatusBar()
    {
        string LoggedInTime = Global::CurrentUserLoginTime;
        string DateStr = LoggedInTime.empty() ? "" : "Login Time: " + LoggedInTime;

        string UserName = Global::CurrentUser.GetUserName();
        string UserStr = UserName.empty() ? "" : "User: " + UserName;

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan);
        UtilLib::PrintHeaderLine('=', _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset);

        string LeftPart = DateStr.empty() ? "" : " " + DateStr;
        string RightPart = UserStr.empty() ? "" : UserStr + " ";

        int LeftLen = (int)LeftPart.length();
        int RightLen = (int)RightPart.length();

        cout << UtilLib::GetColor(UtilLib::enColor::Yellow);

        if (LeftLen > 0 || RightLen > 0)
        {
            int Spaces = _ScreenWidth - LeftLen - RightLen;
            if (Spaces < 0)
                Spaces = 1;

            cout << LeftPart << string(Spaces, ' ') << RightPart << "\n";
        }
        else
        {
            string SystemInfo = Global::AppName + " " + Global::AppVersion;
            int LeftPadding = (_ScreenWidth - (int)SystemInfo.length()) / 2;
            if (LeftPadding < 0)
                LeftPadding = 0;

            cout << string(LeftPadding, ' ') << SystemInfo << "\n";
        }

        cout << UtilLib::GetColor(UtilLib::enColor::Reset);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan);
        UtilLib::PrintHeaderLine('-', _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset);
    }

    void _PrintCenteredLine(string Text, UtilLib::enColor TextColor = UtilLib::enColor::Yellow)
    {
        int TextLength = (int)Text.length();

        int LeftPadding = (_ScreenWidth - TextLength) / 2;
        if (LeftPadding < 0)
            LeftPadding = 0;

        cout << string(LeftPadding, ' ')
             << UtilLib::GetColor(TextColor) << Text << UtilLib::GetColor(UtilLib::enColor::Reset)
             << endl;
    }

    void _PrintFullWidthLine(char LineChar = '=', UtilLib::enColor Color = UtilLib::enColor::Cyan)
    {
        cout << UtilLib::GetColor(Color);
        UtilLib::PrintHeaderLine(LineChar, _ScreenWidth);
        cout << UtilLib::GetColor(UtilLib::enColor::Reset);
    }

    void _PrintCenteredLineWithBorders(const string &Text, UtilLib::enColor TextColor = UtilLib::enColor::Reset)
    {
        int InsideWidth = _ScreenWidth - 2;
        int TextLen = (int)Text.length();

        string DisplayText = (TextLen > InsideWidth) ? Text.substr(0, InsideWidth - 3) + "..." : Text;
        TextLen = (int)DisplayText.length();

        int LeftSpaces = (InsideWidth - TextLen) / 2;
        if (LeftSpaces < 0)
            LeftSpaces = 0;

        int RightSpaces = InsideWidth - TextLen - LeftSpaces;
        if (RightSpaces < 0)
            RightSpaces = 0;

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|";
        cout << string(LeftSpaces, ' ');
        cout << UtilLib::ColorText(DisplayText, TextColor);
        cout << string(RightSpaces, ' ');
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
             << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
    }

    bool _ConfirmUserPassword(string ActionDescription = "CONFIRM SENSITIVE OPERATION", short MaxAttempts = 3)
    {
        short FailedAttempts = 0;
        string EnteredPassword = "";

        while (FailedAttempts < MaxAttempts)
        {
            cout << "\n";
            cout << UtilLib::GetColor(UtilLib::enColor::BrightYellow)
                 << "  [!] SECURITY CHECK REQUIRED: [" << ActionDescription << "]\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);

            string Prompt = "  [?] Enter your current password to authorize: ";
            EnteredPassword = InputValidateLib::ReadPassword(Prompt);

            if (Global::CurrentUser.VerifyPassword(EnteredPassword))
            {
                cout << UtilLib::ColorText("  [+] Identity verified successfully!\n\n", UtilLib::enColor::BrightGreen);
                return true;
            }

            FailedAttempts++;
            short RemainingAttempts = MaxAttempts - FailedAttempts;
            cout << "  [!] WARNING: You have (" << RemainingAttempts << ") attempt(s)";
            cout << UtilLib::GetColor(UtilLib::enColor::BrightRed)
                 << "  [!] WARNING: Invalid password! You have (" << RemainingAttempts << ") attempt(s) before Authorization Failed!." << ".\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);
        }

        cout << "\n";
        _PrintFullWidthLine('=', UtilLib::enColor::BrightRed);
        _PrintCenteredLine("  [!] SECURITY ALERT: Authorization Failed! Operation Aborted.", UtilLib::enColor::BrightRed);
        _PrintFullWidthLine('=', UtilLib::enColor::BrightRed);
        cout << "\n";

        return false;
    }

    bool _CheckAccessRights(clsUser::enMainMenuPermissions Permission)
    {
        if (!Global::CurrentUser.CheckAccessPermission(Permission))
        {
            _ResetTheScreen();
            _DrawScreenHeader("ACCESS DENIED", "You do not have permission to perform this action");

            _PrintFullWidthLine('=', UtilLib::enColor::BrightRed);
            _PrintCenteredLine("  [!] ACCESS DENIED! Please contact your administrator.", UtilLib::enColor::BrightRed);
            _PrintFullWidthLine('=', UtilLib::enColor::BrightRed);

            cout << "\n\n"
                 << UtilLib::ColorText("  [>] Press any key to return to Main Menu...", UtilLib::enColor::Yellow);
            _getch();

            return false;
        }
        return true;
    }

    void _DrawScreenHeader(const string &Title, const string &SubTitle = "")
    {
        _DrawStatusBar();

        cout << "\n";
        _PrintCenteredLine(Title, UtilLib::enColor::BrightYellow);

        if (!SubTitle.empty())
        {
            _PrintCenteredLine(SubTitle, UtilLib::enColor::Yellow);
        }

        cout << "\n";
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