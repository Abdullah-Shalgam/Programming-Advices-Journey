#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Global.h"
#include "clsPerson.h"
#include "MyStringLib.h"
#include "UtilLib.h"

using namespace std;

class clsUser : public clsPerson
{
public:
    // ----------------------------------------------------------
    // 1️⃣ Types, Structs & Enums & Methods(Must be defined first)
    // ----------------------------------------------------------
    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions = 0;
    };

    enum enMainMenuPermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128
    };

    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedUserNameExists = 2
    };

    static clsUser GetEmptyUserObject()
    {
        return {enMode::EmptyMode, "", "", "", "", "", "", 0};
    }

private:
    // ----------------------------------------------------------
    // 2️⃣ Private Members & Mode Enum
    // ----------------------------------------------------------
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    // Constructors
    clsUser(enMode Mode, const string &FirstName, const string &LastName, const string &Email, const string &Phone, const string &UserName, const string &Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _UserName(UserName), _Password(Password), _Permissions(Permissions)
    {
    }

    // ----------------------------------------------------------
    // 3️⃣ Private Helper Converters & Data Loaders (Users)
    // ----------------------------------------------------------

    static clsUser _ConvertLineToUserObject(const string &Line, const string &Separator = "#//#")
    {
        vector<string> vUserData = MyStringLib::SplitString(Line, Separator);

        if (vUserData.size() < 7)
            return GetEmptyUserObject();

        string DecryptedPassword = UtilLib::DecryptText(vUserData[5], Global::EncryptionKey);

        return {enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], DecryptedPassword, stoi(vUserData[6])};
    }

    static string _ConvertUserObjectToLine(const clsUser &User, const string &Separator = "#//#")
    {
        string EncryptedPassword = UtilLib::EncryptText(User.GetPassword(), Global::EncryptionKey);

        return User.GetFirstName() + Separator +
               User.GetLastName() + Separator +
               User.GetEmail() + Separator +
               User.GetPhone() + Separator +
               User.GetUserName() + Separator +
               EncryptedPassword + Separator +
               to_string(User.GetPermissions());
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;
        fstream MyFile(Global::UsersFilePath, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                    vUsers.push_back(_ConvertLineToUserObject(Line));
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(const vector<clsUser> &vUsers)
    {
        fstream MyFile(Global::UsersFilePath, ios::out);
        if (MyFile.is_open())
        {
            for (const clsUser &User : vUsers)
            {
                if (!User._MarkedForDelete)
                {
                    MyFile << _ConvertUserObjectToLine(User) << endl;
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(const string &DataLine)
    {
        fstream MyFile(Global::UsersFilePath, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser &U : vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    bool _MarkForDelete(vector<clsUser> &vUsers)
    {
        for (clsUser &U : vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                return true;
            }
        }
        return false;
    }

    // ----------------------------------------------------------
    // 4️⃣ Private Helper Converters & Data Loaders (Login Register)
    // ----------------------------------------------------------

    string _ConvertLoginRegisterRecordToLine(const string &Separator = "#//#")
    {
        return UtilLib::GetSystemDateTime() + Separator +
               GetUserName() + Separator +
               UtilLib::EncryptText(GetPassword(), Global::EncryptionKey) + Separator +
               to_string(GetPermissions());
    }

    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(const string &Line, const string &Separator = "#//#")
    {
        vector<string> vData = MyStringLib::SplitString(Line, Separator);

        if (vData.size() < 4)
            return {};

        string DecryptedPassword = UtilLib::DecryptText(vData[2], Global::EncryptionKey);

        return {vData[0], vData[1], DecryptedPassword, stoi(vData[3])};
    }

    static vector<stLoginRegisterRecord> _LoadLoginRegisterDataFromFile()
    {
        vector<stLoginRegisterRecord> vRecords;
        fstream MyFile(Global::LoginRegisterFilePath, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                    vRecords.push_back(_ConvertLoginRegisterLineToRecord(Line));
            }
            MyFile.close();
        }
        return vRecords;
    }

public:
    // ----------------------------------------------------------
    // 5️⃣ Public Getters / Setters & Query Methods
    // ----------------------------------------------------------
    bool IsEmpty() const { return (_Mode == enMode::EmptyMode); }
    bool IsMarkedForDelete() const { return _MarkedForDelete; }
    bool VerifyPassword(const string &InputPassword) const { return (this->_Password == InputPassword); }

    // Setters
    void SetUserName(const string &UserName) { _UserName = UserName; }
    void SetPassword(const string &Password) { _Password = Password; }
    void SetPermissions(int Permissions) { _Permissions = Permissions; }

    // Getters
    string GetUserName() const { return _UserName; }
    string GetPassword() const { return _Password; }
    int GetPermissions() const { return _Permissions; }

    // ----------------------------------------------------------
    // 6️⃣ Public Static Operations
    // ----------------------------------------------------------

    static clsUser Find(const string &UserName)
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (const clsUser &User : vUsers)
        {
            if (User.GetUserName() == UserName)
                return User;
        }
        return GetEmptyUserObject();
    }

    static clsUser Find(const string &UserName, const string &Password)
    {
        clsUser User = Find(UserName);

        if (!User.IsEmpty() && User.GetPassword() == Password)
            return User;

        return GetEmptyUserObject();
    }

    static bool IsUserExist(const string &UserName)
    {
        return (!Find(UserName).IsEmpty());
    }

    static clsUser GetAddNewUserObject(const string &UserName)
    {
        return {enMode::AddNewMode, "", "", "", "", UserName, "", 0};
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        return _LoadLoginRegisterDataFromFile();
    }

    // ----------------------------------------------------------
    // 7️⃣ Public Instance Operations
    // ----------------------------------------------------------

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;

        case enMode::AddNewMode:
            if (IsUserExist(_UserName))
            {
                return enSaveResults::svFailedUserNameExists;
            }

            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;

        default:
            return enSaveResults::svFailedEmptyObject;
        }
    }

    bool Delete()
    {
        if (IsEmpty())
            return false;

        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        if (_MarkForDelete(vUsers))
        {
            _SaveUsersDataToFile(vUsers);
            *this = GetEmptyUserObject();
            return true;
        }
        return false;
    }

    bool CheckAccessPermission(enMainMenuPermissions Permission)
    {
        if (this->_Permissions == enMainMenuPermissions::eAll)
            return true;

        if ((Permission & this->_Permissions) == Permission)
            return true;

        return false;
    }

    void RegisterLogin()
    {
        fstream MyFile(Global::LoginRegisterFilePath, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << _ConvertLoginRegisterRecordToLine() << endl;
            MyFile.close();
        }
    }
};