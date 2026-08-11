#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsClientScreenBase.h"
#include "clsBankClient.h"
#include "UtilLib.h"

using namespace std;

class clsClientListScreen : protected clsClientScreenBase
{
private:
    clsClientListScreen() : clsClientScreenBase(122) {}

    void _PrintTableHeader()
    {
        _PrintFullWidthLine('=');

        cout << UtilLib::GetColor(UtilLib::enColor::Bold) << UtilLib::GetColor(UtilLib::enColor::BrightYellow);
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(27) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(15) << "Balance";
        cout << "|";
        cout << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;

        _PrintFullWidthLine('=');
        cout << endl;
    }

    void _PrintClientRecordLine(const clsBankClient &Client)
    {
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::BrightCyan);
        cout << left << setw(15) << Client.GetAccountNumber();

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(27) << Client.GetFullName();

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(12) << Client.GetPhone();

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(30) << Client.GetEmail();

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::Yellow);
        cout << left << setw(10) << Client.GetPinCode();

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::BrightGreen);
        cout << left << setw(15) << _FormatBalance(Client.GetAccountBalance());

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|" << UtilLib::GetColor(UtilLib::enColor::Reset);
    }

    void _PrintFooterSummary(size_t TotalClients, double TotalBalance)
    {
        _PrintFullWidthLine('=');
        cout << endl;

        string SummaryText = "Total Clients: " + to_string(TotalClients) + "  |  Total System Balances: " + _FormatBalance(TotalBalance);
        _PrintCenteredLineWithBorders(SummaryText, UtilLib::enColor::BrightYellow);

        cout << "\n";
        _PrintFullWidthLine('=');
        cout << endl;
    }

    void _Show()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "CLIENTS LIST DASHBOARD";
        string SubTitle = "Active Client Records & Financial Overview";

        _ResetTheScreen();
        _DrawScreenHeader(Title, SubTitle);

        _PrintTableHeader();

        if (vClients.empty())
        {
            _PrintCenteredLineWithBorders("No Clients Available In the System!", UtilLib::enColor::BrightRed);
            cout << "\n";
            _PrintFullWidthLine('=');
            cout << endl;
        }
        else
        {
            double TotalBalance = 0;
            for (const clsBankClient &Client : vClients)
            {
                TotalBalance += Client.GetAccountBalance();
                _PrintClientRecordLine(Client);
                cout << endl;
            }
            _PrintFooterSummary(vClients.size(), TotalBalance);
        }
    }

public:
    static void ShowClientsList()
    {
        clsClientListScreen ClientListScreen;
        ClientListScreen._Show();
    }
};