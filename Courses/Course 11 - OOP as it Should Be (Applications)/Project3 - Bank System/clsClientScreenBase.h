#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsClientScreenBase : protected clsScreen
{
protected:
    clsClientScreenBase(short ScreenWidth = 122) : clsScreen(ScreenWidth) {}

    static string _FormatBalance(double Balance)
    {
        ostringstream ss;
        ss << fixed << setprecision(2) << Balance;
        return "$ " + ss.str();
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
        int LeftSpaces = (InsideWidth - TextLen) / 2;
        int RightSpaces = InsideWidth - TextLen - LeftSpaces;

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|";
        cout << string(LeftSpaces, ' ');
        cout << UtilLib::ColorText(Text, TextColor);
        cout << string(RightSpaces, ' ');
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
             << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
    }

    clsBankClient _GetExistingClient(string PromptMessage = "  [>] Enter Account Number: ")
    {
        cout << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << "  [?] ACCOUNT SEARCH:" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";
        string AccountNumber = InputValidateLib::ReadText(PromptMessage);

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << UtilLib::GetColor(UtilLib::enColor::BrightRed)
                 << "  [!] Account Number [" << AccountNumber << "] was not found! Please try again.\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);
            AccountNumber = InputValidateLib::ReadText(PromptMessage);
        }

        return clsBankClient::Find(AccountNumber);
    }

    void _PrintClientCard(const clsBankClient &Client, string CardTitle = "CLIENT CARD DETAILS")
    {
        const int BoxWidth = 59;
        const int LeftMargin = (_ScreenWidth - BoxWidth) / 2;
        const string Indent(LeftMargin, ' ');
        const string TopBottomLine = string(BoxWidth, '=');

        const int InnerWidth = BoxWidth - 4;
        int TitleLen = (int)CardTitle.length();

        int LeftSpaces = (InnerWidth - TitleLen) / 2;
        if (LeftSpaces < 0)
            LeftSpaces = 0;

        int RightSpaces = InnerWidth - TitleLen - LeftSpaces;
        if (RightSpaces < 0)
            RightSpaces = 0;

        string FormattedTitle = string(LeftSpaces, ' ') + CardTitle + string(RightSpaces, ' ');

        cout << "\n";
        cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << TopBottomLine << endl;

        cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| "
             << UtilLib::GetColor(UtilLib::enColor::BrightYellow);
        UtilLib::TypeWriterText(FormattedTitle, 8);
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;

        cout << Indent << TopBottomLine << endl;

        auto PrintCardRow = [&](string Key, string Value, UtilLib::enColor ValColor = UtilLib::enColor::Reset)
        {
            ostringstream ssKey, ssVal;
            ssKey << left << setw(18) << Key;

            ssVal << left << setw(35) << UtilLib::Truncate(Value, 35);

            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| "
                 << UtilLib::GetColor(UtilLib::enColor::Yellow);
            UtilLib::TypeWriterText(ssKey.str(), 1);

            cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << ": "
                 << UtilLib::GetColor(ValColor);
            UtilLib::TypeWriterText(ssVal.str(), 1);

            cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;
        };

        PrintCardRow("Account Number", Client.GetAccountNumber(), UtilLib::enColor::BrightCyan);
        PrintCardRow("Full Name", Client.GetFullName());
        PrintCardRow("Email", Client.GetEmail());
        PrintCardRow("Phone", Client.GetPhone());
        PrintCardRow("PIN Code", Client.GetPinCode(), UtilLib::enColor::Yellow);
        PrintCardRow("Account Balance", _FormatBalance(Client.GetAccountBalance()), UtilLib::enColor::BrightGreen);

        cout << Indent << TopBottomLine << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n\n";
    }
};