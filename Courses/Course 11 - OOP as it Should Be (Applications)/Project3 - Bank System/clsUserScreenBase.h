#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "clsScreen.h"
#include "clsUser.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsUserScreenBase : protected clsScreen
{
protected:
    clsUserScreenBase(short ScreenWidth = 122) : clsScreen(ScreenWidth) {}

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

    clsUser _GetExistingUser(string PromptMessage = "  [>] Enter Username: ")
    {
        cout << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << "  [?] USER SEARCH:" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";
        string UserName = InputValidateLib::ReadText(PromptMessage);

        while (!clsUser::IsUserExist(UserName))
        {
            cout << UtilLib::GetColor(UtilLib::enColor::BrightRed)
                 << "  [!] Username [" << UserName << "] was not found! Please try again.\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);
            UserName = InputValidateLib::ReadText(PromptMessage);
        }

        return clsUser::Find(UserName);
    }

    string _GetPermissionsText(int Permissions)
    {
        if (Permissions == clsUser::enMainMenuPermissions::eAll)
            return "Full Access";

        string PermText = "";

        if (Permissions & clsUser::enMainMenuPermissions::pListClients)
            PermText += "List, ";
        if (Permissions & clsUser::enMainMenuPermissions::pAddNewClient)
            PermText += "Add, ";
        if (Permissions & clsUser::enMainMenuPermissions::pDeleteClient)
            PermText += "Delete, ";
        if (Permissions & clsUser::enMainMenuPermissions::pUpdateClients)
            PermText += "Update, ";
        if (Permissions & clsUser::enMainMenuPermissions::pFindClient)
            PermText += "Find, ";
        if (Permissions & clsUser::enMainMenuPermissions::pTranactions)
            PermText += "Transactions, ";
        if (Permissions & clsUser::enMainMenuPermissions::pManageUsers)
            PermText += "Manage Users, ";

        if (!PermText.empty())
            PermText = PermText.substr(0, PermText.length() - 2);
        else
            PermText = "No Access";

        return PermText;
    }

    int _ReadPermissionsToSet()
    {
        int Permissions = 0;

        string PromptMsg = UtilLib::GetColor(UtilLib::enColor::BrightYellow) +
                           "  [?] Do you want to give full access? (y/n): " +
                           UtilLib::GetColor(UtilLib::enColor::Reset);

        char Answer = InputValidateLib::getYesNoAnswer(PromptMsg);

        if (tolower(Answer) == 'y')
        {
            return clsUser::enMainMenuPermissions::eAll;
        }

        cout << "\n"
             << UtilLib::GetColor(UtilLib::enColor::BrightYellow)
             << "  [?] SELECT SPECIFIC PERMISSIONS:" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Show Client List? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pListClients;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Add New Client? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pAddNewClient;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Delete Client? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pDeleteClient;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Update Client? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pUpdateClients;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Find Client? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pFindClient;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Transactions Menu? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pTranactions;

        if (tolower(InputValidateLib::getYesNoAnswer("  [>] Manage Users Menu? (y/n): ")) == 'y')
            Permissions |= clsUser::enMainMenuPermissions::pManageUsers;

        return Permissions;
    }

    void _PrintUserCard(const clsUser &User, string CardTitle = "USER CARD DETAILS")
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

        PrintCardRow("Username", User.GetUserName(), UtilLib::enColor::BrightCyan);
        PrintCardRow("Full Name", User.GetFullName());
        PrintCardRow("Email", User.GetEmail());
        PrintCardRow("Phone", User.GetPhone());
        PrintCardRow("Password", User.GetPassword(), UtilLib::enColor::Yellow);

        PrintCardRow("Permissions", _GetPermissionsText(User.GetPermissions()), UtilLib::enColor::BrightGreen);

        cout << Indent << TopBottomLine << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n\n";
    }
};