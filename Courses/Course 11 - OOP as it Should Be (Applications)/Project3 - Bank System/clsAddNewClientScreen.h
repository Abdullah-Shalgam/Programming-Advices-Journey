#pragma once
#include <iostream>
#include "clsClientScreenBase.h"
#include "clsBankClient.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsAddNewClientScreen : protected clsClientScreenBase
{
private:
    clsAddNewClientScreen() : clsClientScreenBase(122) {}

    void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\n"
             << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << "  [+] ENTER CLIENT INFORMATION:" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "  --------------------------------------------------------" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";

        Client.SetFirstName(InputValidateLib::ReadText("  [>] Enter First Name          : "));
        Client.SetLastName(InputValidateLib::ReadText("  [>] Enter Last Name           : "));
        Client.SetEmail(InputValidateLib::ReadText("  [>] Enter Email Address       : "));
        Client.SetPhone(InputValidateLib::ReadText("  [>] Enter Phone Number        : "));
        Client.SetPinCode(InputValidateLib::GetValidPIN("  [>] Enter PIN Code (4 digits) : "));
        Client.SetAccountBalance(InputValidateLib::ReadDblPositiveNumber("  [>] Enter Initial Balance     : "));

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "  --------------------------------------------------------" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";
    }

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("ADD NEW CLIENT DASHBOARD", "Register New Bank Account Record");

        cout << UtilLib::GetColor(UtilLib::enColor::BrightYellow) << "  [?] ACCOUNT VERIFICATION:" << UtilLib::GetColor(UtilLib::enColor::Reset) << "\n";
        string AccountNumber = InputValidateLib::ReadText("  [>] Enter Account Number: ");

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << UtilLib::GetColor(UtilLib::enColor::BrightRed)
                 << "  [!] Account Number [" << AccountNumber << "] is already taken! Please try another.\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);
            AccountNumber = InputValidateLib::ReadText("  [>] Enter New Account Number: ");
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        cout << "\n";
        _ShowProgressBar("Saving new client to database...");

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\n\n";
            _PrintAnimatedSuccess("  [!] Client Account Created Successfully!", 20);
            _PrintClientCard(NewClient, "NEW CLIENT CARD DETAILS");
            break;

        case clsBankClient::enSaveResults::svFaildEmptyObject:
            _ShowWarningMessage("ERROR: Save failed because the client object is empty!");
            break;

        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            _ShowWarningMessage("ERROR: Save failed because the Account Number already exists!");
            break;
        }
    }

public:
    static void ShowAddNewClient()
    {
        clsAddNewClientScreen AddNewClientScreen;
        AddNewClientScreen._Show();
    }
};