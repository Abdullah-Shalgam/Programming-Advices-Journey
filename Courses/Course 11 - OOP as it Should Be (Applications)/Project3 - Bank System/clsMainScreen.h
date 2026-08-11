#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "clsScreen.h"
#include "InputValidateLib.h"

// Screens
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"

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
        eLogout = 8
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

    void _ShowAllClientsScreen()
    {
        _ShowProgressBar("Fetching client records from database...");
        clsClientListScreen::ShowClientsList();
    }

    void _ShowAddNewClientsScreen()
    {
        _ShowProgressBar("Initializing client registration system...");
        clsAddNewClientScreen::ShowAddNewClient();
    }

    void _ShowDeleteClientScreen()
    {
        _ShowProgressBar("Initializing client removal system...");
        clsDeleteClientScreen::ShowDeleteClient();
    }

    void _ShowUpdateClientScreen()
    {
        _ShowProgressBar("Initializing client update module...");
        clsUpdateClientScreen::ShowUpdateClient();
    }

    void _ShowFindClientScreen()
    {
        _ShowProgressBar("Initializing client search module...");
        clsFindClientScreen::ShowFindClient();
    }

    void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menu Will be here...\n";
    }

    void _ShowManageUsersMenu()
    {
        cout << "\nUsers Menu Will be here...\n";
    }

    void _ShowEndScreen()
    {
        _ResetTheScreen();
        _DrawScreenHeader("SYSTEM SHUTDOWN", "Session Logout");
        _PrintAnimatedSuccess("  [!] Logging out safely... Thank you for using Bank System!", 25);
        _ShowLoadingSpinner("Closing secure connection...", 2);
        cout << "\n";
    }

    // ----------------------------------------------------------
    // User Interface Components
    // ----------------------------------------------------------

    void _DrawMenuBox()
    {
        int BoxWidth = 58;
        int LeftMargin = (_ScreenWidth - BoxWidth) / 2;
        string Indent(LeftMargin, ' ');

        // Top Frame Header
        cout << Indent << UtilLib::GetColor(UtilLib::enColor::Cyan) << "===========================================================" << endl;
        cout << Indent << "| " << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << "                 SYSTEM MAIN DASHBOARD                 " << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;
        cout << Indent << "===========================================================" << endl;

        // Section 1: Client Management
        cout << Indent << "| " << UtilLib::GetColor(UtilLib::enColor::BrightGreen) << " -- CLIENT MANAGEMENT SERVICES --                      " << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;

        auto PrintOption = [&](string Num, string Label, UtilLib::enColor NumColor = UtilLib::enColor::Yellow)
        {
            cout << Indent << "|   "
                 << UtilLib::GetColor(NumColor) << "[" << Num << "]"
                 << UtilLib::GetColor(UtilLib::enColor::Reset) << " "
                 << left << setw(49) << Label
                 << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;
        };

        PrintOption("1", "Show Client List");
        PrintOption("2", "Add New Client");
        PrintOption("3", "Delete Client");
        PrintOption("4", "Update Client Info");
        PrintOption("5", "Find Client");

        // Separator Line
        cout << Indent << "| " << UtilLib::GetColor(UtilLib::enColor::Cyan) << "------------------------------------------------------- |" << endl;

        // Section 2: Administrative & System Operations
        cout << Indent << "| " << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << " -- BANK OPERATIONS & ADMIN --                         " << UtilLib::GetColor(UtilLib::enColor::Cyan) << " |" << endl;

        PrintOption("6", "Transactions Menu");
        PrintOption("7", "Manage Users");

        // Separator Line
        cout << Indent << "| " << UtilLib::GetColor(UtilLib::enColor::Cyan) << "------------------------------------------------------- |" << endl;

        // Section 3: Session Management
        PrintOption("8", "Logout & Exit Session", UtilLib::enColor::BrightRed);

        // Bottom Frame Footer
        cout << Indent << "===========================================================" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n\n";
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
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eAddNewClient:
            _ResetTheScreen();
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            _ResetTheScreen();
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            _ResetTheScreen();
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            _ResetTheScreen();
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenu:
            _ResetTheScreen();
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            _ResetTheScreen();
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eLogout:
            _ShowEndScreen();
            break;
        }
    }

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("MAIN DASHBOARD", "Select an option from the menu below");
        _DrawMenuBox();

        string Prompt = "  [?] Choose Option [1 to 8]: ";
        short Choice = InputValidateLib::ReadShortNumberInRange(1, 8, Prompt, "  [!] Invalid Option! Enter Number between 1 and 8: ");
        _PerformMainMenuOption((enMainMenuOptions)Choice);
    }

public:
    static void ShowMainMenu()
    {
        clsMainScreen MainScreen;
        MainScreen._Show();
    }
};