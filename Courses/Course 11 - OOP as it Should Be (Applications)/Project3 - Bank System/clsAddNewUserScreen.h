#pragma once
#include <iostream>
#include <string>
#include "clsUserScreenBase.h"
#include "clsUser.h"
#include "InputValidateLib.h"
#include "UtilLib.h"

using namespace std;

class clsAddNewUserScreen : protected clsUserScreenBase
{
private:
    clsAddNewUserScreen() : clsUserScreenBase(122) {}

    void _ReadUserInfo(clsUser &User)
    {
        cout << "\n"
             << UtilLib::ColorText("  [+] ENTER USER INFORMATION:", UtilLib::enColor::BrightYellow) << "\n";
        UtilLib::PrintHeaderLine('-', 56);

        User.SetFirstName(InputValidateLib::ReadText("  [>] Enter First Name    : "));
        User.SetLastName(InputValidateLib::ReadText("  [>] Enter Last Name     : "));
        User.SetEmail(InputValidateLib::ReadText("  [>] Enter Email Address : "));
        User.SetPhone(InputValidateLib::ReadText("  [>] Enter Phone Number  : "));

        User.SetPassword(InputValidateLib::ReadPassword("  [>] Enter Password      : "));
        User.SetPermissions(_ReadPermissionsToSet());

        UtilLib::PrintHeaderLine('-', 56);
    }

    void _Show()
    {
        _ResetTheScreen();
        _DrawScreenHeader("ADD NEW USER DASHBOARD", "Register New System User Record");

        cout << UtilLib::ColorText("  [?] USER VERIFICATION:", UtilLib::enColor::BrightYellow) << "\n";
        string UserName = InputValidateLib::ReadText("  [>] Enter Username: ");

        while (clsUser::IsUserExist(UserName))
        {
            cout << UtilLib::ColorText("  [!] Username [" + UserName + "] is already taken! Please try another.\n", UtilLib::enColor::BrightRed);
            UserName = InputValidateLib::ReadText("  [>] Enter New Username: ");
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        cout << "\n";
        _ShowProgressBar("Saving new user to database...");

        clsUser::enSaveResults SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\n\n";
            _PrintAnimatedSuccess("  [!] User Account Created Successfully!", 20);
            _PrintUserCard(NewUser, "NEW USER CARD DETAILS");
            break;

        case clsUser::enSaveResults::svFailedEmptyObject:
            _ShowWarningMessage("ERROR: Save failed because the user object is empty!");
            break;

        case clsUser::enSaveResults::svFailedUserNameExists:
            _ShowWarningMessage("ERROR: Save failed because the Username already exists!");
            break;
        }
    }

public:
    static void ShowAddNewUser()
    {
        clsAddNewUserScreen AddNewUserScreen;
        AddNewUserScreen._Show();
    }
};