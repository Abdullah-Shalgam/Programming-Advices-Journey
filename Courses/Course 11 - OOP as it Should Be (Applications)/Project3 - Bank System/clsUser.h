#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "clsPerson.h"
#include "MyStringLib.h"
#include "UtilLib.h"

using namespace std;

const string UsersFileName = "Users.txt";

class clsUser : public clsPerson
{
private:
    static const short _EncryptionKey = 10;

    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;

    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    clsUser(enMode Mode, const string &FirstName, const string &LastName, const string &Email, const string &Phone, const string &UserName, const string &Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _UserName(UserName), _Password(Password), _Permissions(Permissions)
    {
    }

    static clsUser _ConvertLineToUserObject(const string &line, const string &separator = "#//#")
    {
        vector<string> vUserData = MyStringLib::SplitString(line, separator);

        string DecryptedPassword = UtilLib::DecryptText(vUserData[5], _EncryptionKey);

        return {enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], DecryptedPassword, stoi(vUserData[6])};
    }

    static string _ConvertUserObjectToLine(const clsUser &User, const string &separator = "#//#")
    {
        string EncryptedPassword = UtilLib::EncryptText(User.GetPassword(), _EncryptionKey);

        return User.GetFirstName() + separator +
               User.GetLastName() + separator +
               User.GetEmail() + separator +
               User.GetPhone() + separator +
               User.GetUserName() + separator +
               EncryptedPassword + separator +
               to_string(User.GetPermissions());
    }

    static vector<clsUser> _LoadUsersDataFromFile(const string &FileName)
    {
        vector<clsUser> vUsers;
        fstream MyFile(FileName, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                    vUsers.push_back(_ConvertLineToUserObject(line));
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(const string &FileName, const vector<clsUser> &vUsers)
    {
        fstream MyFile(FileName, ios::out);
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

    void _Update(const string &FileName)
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile(FileName);

        for (clsUser &U : vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(FileName, vUsers);
    }

    void _AddDataLineToFile(const string &FileName, const string &DataLine)
    {
        fstream MyFile(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    void _AddNew(const string &FileName)
    {
        _AddDataLineToFile(FileName, _ConvertUserObjectToLine(*this));
    }

    static clsUser _GetEmptyUserObject()
    {
        return {enMode::EmptyMode, "", "", "", "", "", "", 0};
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

public:
    enum enMainMenuPermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTranactions = 32,
        pManageUsers = 64
    };

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool IsMarkedForDelete()
    {
        return _MarkedForDelete;
    }

    // Setters
    void SetUserName(const string &UserName) { _UserName = UserName; }
    void SetPassword(const string &Password) { _Password = Password; }
    void SetPermissions(int Permissions) { _Permissions = Permissions; }

    // Getters
    string GetUserName() const { return _UserName; }
    string GetPassword() const { return _Password; }
    int GetPermissions() const { return _Permissions; }

    static clsUser Find(const string &UserName)
    {
        fstream MyFile(UsersFileName, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                {
                    clsUser User = _ConvertLineToUserObject(line);

                    if (User.GetUserName() == UserName)
                    {
                        MyFile.close();
                        return User;
                    }
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(const string &UserName, const string &Password)
    {
        fstream MyFile(UsersFileName, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                {
                    clsUser User = _ConvertLineToUserObject(line);

                    if (User.GetUserName() == UserName && User.GetPassword() == Password)
                    {
                        MyFile.close();
                        return User;
                    }
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedUserNameExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode:
            _Update(UsersFileName);
            return enSaveResults::svSucceeded;

        case enMode::AddNewMode:
            if (IsUserExist(_UserName))
            {
                return enSaveResults::svFailedUserNameExists;
            }

            _AddNew(UsersFileName);
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;

        default:
            return enSaveResults::svFailedEmptyObject;
        }
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
        return _LoadUsersDataFromFile(UsersFileName);
    }

    bool Delete()
    {
        if (IsEmpty())
            return false;

        vector<clsUser> vUsers = _LoadUsersDataFromFile(UsersFileName);

        if (_MarkForDelete(vUsers))
        {
            _SaveUsersDataToFile(UsersFileName, vUsers);
            *this = _GetEmptyUserObject();
            return true;
        }
        return false;
    }
};