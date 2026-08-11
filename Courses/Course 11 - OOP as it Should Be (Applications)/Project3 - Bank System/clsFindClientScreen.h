#pragma once
#include <iostream>
#include "clsClientScreenBase.h"
#include "clsBankClient.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsFindClientScreen : protected clsClientScreenBase
{
private:
    clsFindClientScreen() : clsClientScreenBase(122) {}

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("FIND CLIENT DASHBOARD", "Search & Display Existing Client Record");

        clsBankClient Client = _GetExistingClient("  [>] Enter Account Number: ");

        cout << "\n";
        _ShowProgressBar("Fetching client record from database...");

        cout << "\n\n";
        _PrintAnimatedSuccess("  [!] Client Record Found & Retrieved Successfully!", 20);

        _PrintClientCard(Client, "CLIENT CARD DETAILS");
    }

public:
    static void ShowFindClient()
    {
        clsFindClientScreen FindClientScreen;
        FindClientScreen._Show();
    }
};