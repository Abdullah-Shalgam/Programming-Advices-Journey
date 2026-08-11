#pragma once
#include <iostream>
#include "clsClientScreenBase.h"
#include "clsBankClient.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsDeleteClientScreen : protected clsClientScreenBase
{
private:
    clsDeleteClientScreen() : clsClientScreenBase(122) {}

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("DELETE CLIENT DASHBOARD", "Remove Existing Client Record Permanently");

        clsBankClient Client = _GetExistingClient("  [>] Enter Account Number: ");
        _PrintClientCard(Client, "CLIENT CARD DETAILS TO DELETE");

        string PromptMsg = UtilLib::GetColor(UtilLib::enColor::BrightRed) + "  [!] WARNING: Are you sure you want to delete this client permanently? (y/n): " + UtilLib::GetColor(UtilLib::enColor::Reset);

        char Answer = InputValidateLib::getYesNoAnswer(PromptMsg);

        if (tolower(Answer) == 'y')
        {
            cout << "\n";
            _ShowProgressBar("Deleting client record permanently from database...");

            if (Client.Delete())
            {
                cout << "\n\n";
                _PrintAnimatedSuccess("  [!] Client Record Deleted Permanently!", 20);
            }
            else
            {
                _ShowWarningMessage("ERROR: Failed to delete client record!");
            }
        }
        else
        {
            cout << UtilLib::GetColor(UtilLib::enColor::Yellow)
                 << "\n  [i] Deletion operation cancelled. Client record remains safe.\n"
                 << UtilLib::GetColor(UtilLib::enColor::Reset);
        }
    }

public:
    static void ShowDeleteClient()
    {
        clsDeleteClientScreen DeleteClientScreen;
        DeleteClientScreen._Show();
    }
};