#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsUserScreenBase.h"
#include "clsUser.h"
#include "UtilLib.h"

using namespace std;

class clsUsersListScreen : protected clsUserScreenBase
{
private:
    clsUsersListScreen() : clsUserScreenBase(122) {}

    void _PrintTableHeader()
    {
        _PrintFullWidthLine('=');

        cout << UtilLib::GetColor(UtilLib::enColor::Bold) << UtilLib::GetColor(UtilLib::enColor::BrightYellow);
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(27) << "Full Name";
        cout << "| " << left << setw(11) << "Phone";
        cout << "| " << left << setw(35) << "Email";
        cout << "| " << left << setw(9) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "|";
        cout << UtilLib::GetColor(UtilLib::enColor::Reset) << endl;

        _PrintFullWidthLine('=');
        cout << endl;
    }

    void _PrintUserRecordLine(const clsUser &User)
    {
        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "| " << UtilLib::GetColor(UtilLib::enColor::BrightCyan);
        cout << left << setw(15) << UtilLib::Truncate(User.GetUserName(), 13);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " | " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(25) << UtilLib::Truncate(User.GetFullName(), 23);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " | " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(15) << UtilLib::Truncate(User.GetPhone(), 13);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " | " << UtilLib::GetColor(UtilLib::enColor::Reset);
        cout << left << setw(30) << UtilLib::Truncate(User.GetEmail(), 28);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " | " << UtilLib::GetColor(UtilLib::enColor::BrightYellow);
        cout << left << setw(12) << UtilLib::Truncate(User.GetPassword(), 10);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << " | " << UtilLib::GetColor(UtilLib::enColor::BrightGreen);
        cout << left << setw(12) << UtilLib::Truncate(_GetPermissionsText(User.GetPermissions()), 12);

        cout << UtilLib::GetColor(UtilLib::enColor::Cyan) << "|" << UtilLib::GetColor(UtilLib::enColor::Reset);
    }

    void _PrintFooterSummary(size_t TotalUsers)
    {
        _PrintFullWidthLine('=');
        cout << endl;

        string SummaryText = "Total Users: " + to_string(TotalUsers);
        _PrintCenteredLineWithBorders(SummaryText, UtilLib::enColor::BrightYellow);

        cout << "\n";
        _PrintFullWidthLine('=');
        cout << endl;
    }

    void _Show()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();

        string Title = "USERS LIST DASHBOARD";
        string SubTitle = "Active User Records & System Permissions";

        _ResetTheScreen();
        _DrawScreenHeader(Title, SubTitle);

        _PrintTableHeader();

        if (vUsers.empty())
        {
            _PrintCenteredLineWithBorders("No Users Available In the System!", UtilLib::enColor::BrightRed);
            cout << "\n";
            _PrintFullWidthLine('=');
            cout << endl;
        }
        else
        {
            for (const clsUser &User : vUsers)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
            _PrintFooterSummary(vUsers.size());
        }
    }

public:
    static void ShowUsersList()
    {
        clsUsersListScreen UsersListScreen;
        UsersListScreen._Show();
    }
};