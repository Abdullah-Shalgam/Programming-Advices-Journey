#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>

#include "clsScreen.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

// Screens
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsLogoutScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum class enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eLogout = 9
    };

    clsMainScreen() : clsScreen(122) {}

    // ----------------------------------------------------------
    // Navigation & Screen Dispatchers
    // ----------------------------------------------------------

    void _GoBackToMainMenu()
    {
        cout << "\n\n"
             << UtilLib::ColorText("  [>] Press any key to return to Main Menu...", UtilLib::enColor::Yellow);
        _getch();
        _Show();
    }

    bool _ShowAllClientsScreen()
    {
        _ShowProgressBar("Fetching client records from database...");
        return clsClientsListScreen::ShowClientsList();
    }

    bool _ShowAddNewClientsScreen()
    {
        _ShowProgressBar("Initializing client registration system...");
        return clsAddNewClientScreen::ShowAddNewClient();
    }

    bool _ShowDeleteClientScreen()
    {
        _ShowProgressBar("Initializing client removal system...");
        return clsDeleteClientScreen::ShowDeleteClient();
    }

    bool _ShowUpdateClientScreen()
    {
        _ShowProgressBar("Initializing client update module...");
        return clsUpdateClientScreen::ShowUpdateClient();
    }

    bool _ShowFindClientScreen()
    {
        _ShowProgressBar("Initializing client search module...");
        return clsFindClientScreen::ShowFindClient();
    }

    void _ShowTransactionsMenu()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
        _Show();
    }

    void _ShowManageUsersMenu()
    {
        clsManageUsersScreen::ShowManageUsersMenu();
        _Show();
    }

    bool _ShowLoginRegisterScreen()
    {
        _ShowProgressBar("Opening Login Register Audit Log...");
        return clsLoginRegisterScreen::ShowLoginRegister();
    }

    void _ShowLogoutScreen()
    {
        clsLogoutScreen::ShowLogoutScreen();
    }

    // ----------------------------------------------------------
    // User Interface Components
    // ----------------------------------------------------------

    void _DrawMenuBox()
    {
        const int BoxWidth = 60;
        const int InnerWidth = BoxWidth - 2;
        const int LeftMargin = (_ScreenWidth - BoxWidth) / 2;
        const string Indent(LeftMargin > 0 ? LeftMargin : 0, ' ');

        auto PrintFrameLine = [&](char FillChar = '=')
        {
            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan)
                 << string(BoxWidth, FillChar)
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
        };

        auto PrintCenteredTitle = [&](string Text, UtilLib::enColor TextColor = UtilLib::enColor::BrightYellow)
        {
            int TextLen = (int)Text.length();
            int Padding = InnerWidth - TextLen;
            int LeftPad = Padding / 2;
            int RightPad = Padding - LeftPad;

            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
                 << string(LeftPad, ' ')
                 << UtilLib::GetColor(TextColor) << Text
                 << UtilLib::GetColor(UtilLib::enColor::Cyan) << string(RightPad, ' ') << "|"
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
        };

        auto PrintSectionHeader = [&](string Text, UtilLib::enColor TextColor = UtilLib::enColor::BrightGreen)
        {
            int LeftPad = 2;
            int RightPad = InnerWidth - LeftPad - (int)Text.length();
            if (RightPad < 0)
                RightPad = 0;

            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
                 << string(LeftPad, ' ')
                 << UtilLib::GetColor(TextColor) << Text
                 << UtilLib::GetColor(UtilLib::enColor::Cyan) << string(RightPad, ' ') << "|"
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
        };

        auto PrintOption = [&](string Num, string Label, UtilLib::enColor NumColor = UtilLib::enColor::Yellow)
        {
            int IndentInside = 3;
            string NumTag = "[" + Num + "]";
            int UsedWidth = IndentInside + (int)NumTag.length() + 1 + (int)Label.length();
            int RightPad = InnerWidth - UsedWidth;
            if (RightPad < 0)
                RightPad = 0;

            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
                 << string(IndentInside, ' ')
                 << UtilLib::GetColor(NumColor) << NumTag
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << " "
                 << Label
                 << UtilLib::GetColor(UtilLib::enColor::Cyan) << string(RightPad, ' ') << "|"
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
        };

        auto PrintSeparator = [&](char FillChar = '-')
        {
            int Pad = 1;
            int LineLen = InnerWidth - (Pad * 2);
            cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|"
                 << string(Pad, ' ') << string(LineLen, FillChar) << string(Pad, ' ') << "|"
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;
        };

        PrintFrameLine('=');
        PrintCenteredTitle("SYSTEM MAIN DASHBOARD");
        PrintFrameLine('=');

        // Section 1: Client Management
        PrintSectionHeader("-- CLIENT MANAGEMENT SERVICES --", UtilLib::enColor::BrightGreen);
        PrintOption("1", "Show Client List");
        PrintOption("2", "Add New Client");
        PrintOption("3", "Delete Client");
        PrintOption("4", "Update Client Info");
        PrintOption("5", "Find Client");

        PrintSeparator('-');

        // Section 2: Operations & Audit
        PrintSectionHeader("-- BANK OPERATIONS & AUDIT --", UtilLib::enColor::BrightYellow);
        PrintOption("6", "Transactions Menu");
        PrintOption("7", "Manage Users");
        PrintOption("8", "Login Register");

        PrintSeparator('-');

        // Section 3: Session
        PrintOption("9", "Logout & Exit Session", UtilLib::enColor::BrightRed);

        PrintFrameLine('=');
        cout << "\n";
    }

    // ----------------------------------------------------------
    // Main Command Processing Loop
    // ----------------------------------------------------------

    void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
            _ResetTheScreen();
            if (_ShowAllClientsScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eAddNewClient:
            _ResetTheScreen();
            if (_ShowAddNewClientsScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            _ResetTheScreen();
            if (_ShowDeleteClientScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            _ResetTheScreen();
            if (_ShowUpdateClientScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            _ResetTheScreen();
            if (_ShowFindClientScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenu:
            _ResetTheScreen();
            _ShowTransactionsMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            _ResetTheScreen();
            _ShowManageUsersMenu();
            break;

        case enMainMenuOptions::eLoginRegister:
            _ResetTheScreen();
            if (_ShowLoginRegisterScreen())
                _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eLogout:
            _ShowLogoutScreen();
            break;
        }
    }

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("MAIN DASHBOARD", "Select an option from the menu below");
        _DrawMenuBox();

        string Prompt = "  [?] Choose Option [1 to 9]: ";
        short Choice = InputValidateLib::ReadShortNumberInRange(1, 9, Prompt, "  [!] Invalid Option! Enter Number between 1 and 9: ");
        _PerformMainMenuOption((enMainMenuOptions)Choice);
    }

public:
    static void ShowMainMenu()
    {
        clsMainScreen MainScreen;
        MainScreen._Show();
    }
};