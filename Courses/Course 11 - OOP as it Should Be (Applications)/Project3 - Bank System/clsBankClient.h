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

class clsBankClient : public clsPerson
{
private:
    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;

    // Private Constructors
    clsBankClient(enMode Mode, const string &FirstName, const string &LastName, const string &Email, const string &Phone, const string &AccountNumber, const string &PinCode, const double AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _AccountNumber(AccountNumber), _PinCode(PinCode), _AccountBalance(AccountBalance)
    {
    }

    // ----------------------------------------------------------
    // Private Helper Converters & Data Loaders
    // ----------------------------------------------------------

    static clsBankClient _ConvertLineToClientObject(const string &Line, const string &Separator = "#//#")
    {
        vector<string> vClientData = MyStringLib::SplitString(Line, Separator);

        if (vClientData.size() < 7)
            return _GetEmptyClientObject();

        string DecryptedPinCode = UtilLib::DecryptText(vClientData[5], Global::EncryptionKey);

        return {enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], DecryptedPinCode, stod(vClientData[6])};
    }

    static string _ConvertClientObjectToLine(const clsBankClient &Client, const string &Separator = "#//#")
    {
        ostringstream ss;
        ss << fixed << setprecision(6) << Client.GetAccountBalance();

        string EncryptedPinCode = UtilLib::EncryptText(Client.GetPinCode(), Global::EncryptionKey);

        return Client.GetFirstName() + Separator +
               Client.GetLastName() + Separator +
               Client.GetEmail() + Separator +
               Client.GetPhone() + Separator +
               Client.GetAccountNumber() + Separator +
               EncryptedPinCode + Separator +
               ss.str();
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile(Global::ClientsFilePath, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                    vClients.push_back(_ConvertLineToClientObject(Line));
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientsDataToFile(const vector<clsBankClient> &vClients)
    {
        fstream MyFile(Global::ClientsFilePath, ios::out);
        if (MyFile.is_open())
        {
            for (const clsBankClient &Client : vClients)
            {
                if (!Client._MarkedForDelete)
                {
                    MyFile << _ConvertClientObjectToLine(Client) << endl;
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(const string &DataLine)
    {
        fstream MyFile(Global::ClientsFilePath, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return {enMode::EmptyMode, "", "", "", "", "", "", 0};
    }

    bool _MarkForDelete(vector<clsBankClient> &vClients)
    {
        for (clsBankClient &C : vClients)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                return true;
            }
        }
        return false;
    }

public:
    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

    // Status Queries
    bool IsEmpty() const { return (_Mode == enMode::EmptyMode); }
    bool IsMarkedForDelete() const { return _MarkedForDelete; }

    // Setters
    void SetPinCode(const string &PinCode) { _PinCode = PinCode; }
    void SetAccountBalance(const double AccountBalance) { _AccountBalance = AccountBalance; }

    // Getters
    string GetAccountNumber() const { return _AccountNumber; }
    string GetPinCode() const { return _PinCode; }
    double GetAccountBalance() const { return _AccountBalance; }

    // ----------------------------------------------------------
    // Public Static Operations
    // ----------------------------------------------------------

    static clsBankClient Find(const string &AccountNumber)
    {
        fstream MyFile(Global::ClientsFilePath, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                {
                    clsBankClient Client = _ConvertLineToClientObject(line);

                    if (Client.GetAccountNumber() == AccountNumber)
                    {
                        MyFile.close();
                        return Client;
                    }
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(const string &AccountNumber, const string &PinCode)
    {
        clsBankClient Client = Find(AccountNumber);

        if (!Client.IsEmpty() && Client.GetPinCode() == PinCode)
            return Client;

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(const string &AccountNumber)
    {
        return (!Find(AccountNumber).IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(const string &AccountNumber)
    {
        return {enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0};
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = GetClientsList();

        double TotalBalances = 0;
        for (const clsBankClient &Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
    }

    // ----------------------------------------------------------
    // Public Instance Operations
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
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }

            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;

        default:
            return enSaveResults::svFailedEmptyObject;
        }
    }

    bool Deposit(double Amount)
    {
        _AccountBalance += Amount;
        return (Save() == enSaveResults::svSucceeded);
    }

    bool Withdraw(double Amount)
    {
        _AccountBalance -= Amount;
        return (Save() == enSaveResults::svSucceeded);
    }

    bool Delete()
    {
        if (IsEmpty())
            return false;

        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        if (_MarkForDelete(vClients))
        {
            _SaveClientsDataToFile(vClients);
            *this = _GetEmptyClientObject();
            return true;
        }
        return false;
    }
};