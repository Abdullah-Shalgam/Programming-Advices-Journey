#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "clsPerson.h"
#include "MyStringLib.h"

using namespace std;

const string ClientsFileName = "Clients.txt";

class clsBankClient : public clsPerson
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

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;

    clsBankClient(enMode Mode, const string &FirstName, const string &LastName, const string &Email, const string &Phone, const string &AccountNumber, const string &PinCode, const double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _AccountNumber(AccountNumber), _PinCode(PinCode), _AccountBalance(AccountBalance)
    {
    }

    static clsBankClient _ConvertLineToClientObject(const string &line, const string &separator = "#//#")
    {
        vector<string> vClientData = MyStringLib::SplitString(line, separator);

        string DecryptedPinCode = UtilLib::DecryptText(vClientData[5], _EncryptionKey);

        return {enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], DecryptedPinCode, stod(vClientData[6])};
    }

    static string _ConvertClientObjectToLine(const clsBankClient &Client, const string &separator = "#//#")
    {
        ostringstream ss;
        ss << fixed << setprecision(6) << Client.GetAccountBalance();

        string EncryptedPinCode = UtilLib::EncryptText(Client.GetPinCode(), _EncryptionKey);

        return Client.GetFirstName() + separator +
               Client.GetLastName() + separator +
               Client.GetEmail() + separator +
               Client.GetPhone() + separator +
               Client.GetAccountNumber() + separator +
               EncryptedPinCode + separator +
               ss.str();
    }

    static vector<clsBankClient> _LoadClientsDataFromFile(const string &FileName)
    {
        vector<clsBankClient> vClients;
        fstream MyFile(FileName, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                    vClients.push_back(_ConvertLineToClientObject(line));
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientsDataToFile(const string &FileName, const vector<clsBankClient> &vClients)
    {
        fstream MyFile(FileName, ios::out);
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

    void _Update(const string &FileName)
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile(FileName);

        for (clsBankClient &C : vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(FileName, vClients);
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
        _AddDataLineToFile(FileName, _ConvertClientObjectToLine(*this));
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
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool IsMarkedForDelete()
    {
        return _MarkedForDelete;
    }

    // Setters
    void SetPinCode(const string &PinCode) { _PinCode = PinCode; }
    void SetAccountBalance(const double AccountBalance) { _AccountBalance = AccountBalance; }

    // Getters
    string GetAccountNumber() const { return _AccountNumber; }
    string GetPinCode() const { return _PinCode; }
    double GetAccountBalance() const { return _AccountBalance; }

    static clsBankClient Find(const string &AccountNumber)
    {
        fstream MyFile(ClientsFileName, ios::in);

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
        fstream MyFile(ClientsFileName, ios::in);

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                if (!line.empty())
                {
                    clsBankClient Client = _ConvertLineToClientObject(line);

                    if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
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

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;

        case enMode::UpdateMode:
        {
            _Update(ClientsFileName);
            return enSaveResults::svSucceeded;
        }

        case enMode::AddNewMode:
        {
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }

            _AddNew(ClientsFileName);
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;
        }

        default:
            return enSaveResults::svFailedEmptyObject;
        }
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
        return _LoadClientsDataFromFile(ClientsFileName);
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;
        for (const clsBankClient &Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
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

        vector<clsBankClient> vClients = _LoadClientsDataFromFile(ClientsFileName);

        if (_MarkForDelete(vClients))
        {
            _SaveClientsDataToFile(ClientsFileName, vClients);
            *this = _GetEmptyClientObject();
            return true;
        }
        return false;
    }
};