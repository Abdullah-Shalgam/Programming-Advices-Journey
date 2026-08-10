#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "clsPerson.h"
#include "MyStringLib.h"
#include "InputValidateLib.h"

using namespace std;

const string ClientsFileName = "Clients.txt";

class clsBankClient : public clsPerson
{
private:
    enum class enMode { EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;

    static clsBankClient _ConvertLineToClientObject(const string& line, const string& separator = "#//#")
    {
        vector<string> vClientData = MyStringLib::SplitString(line, separator);

        return { enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]) };
    }

    static  string _ConvertClientObjectToLine(const clsBankClient& Client, const string& separator = "#//#")
    {
        ostringstream ss;
        ss << fixed << setprecision(6) << Client.GetAccountBalance();
        
        return Client.GetFirstName() + separator +
            Client.GetLastName() + separator +
            Client.GetEmail() + separator +
            Client.GetPhone() + separator +
            Client.GetAccountNumber() + separator +
            Client.GetPinCode() + separator +
            ss.str();
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return {enMode::EmptyMode, "", "", "", "", "", "", 0 };
    }

    static vector<clsBankClient> _LoadClientsDataFromFile(const string& FileName)
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

    static void _SaveClientsDataToFile(const string& FileName, const vector<clsBankClient>& vClients)
    {
        fstream MyFile(FileName, ios::out);
        if (MyFile.is_open())
        {
            for (const clsBankClient& Client : vClients)
            {
                MyFile << _ConvertClientObjectToLine(Client) << endl;
            }
            MyFile.close();
        }
    }

    void _Update(const string& FileName)
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile(FileName);

        for (clsBankClient& C : vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(FileName, vClients);
    }

    void _AddDataLineToFile(const string& FileName, const string& DataLine)
    {
        fstream MyFile(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

public:

    clsBankClient(enMode Mode, const string& FirstName, const string& LastName, const string& Email, const string& Phone, const string& AccountNumber, const string& PinCode, const double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _AccountNumber(AccountNumber), _PinCode(PinCode), _AccountBalance(AccountBalance)
    {
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Setters
    void SetPinCode(const string& PinCode) { _PinCode = PinCode; }
    void SetAccoutBalance(const double AccountBalance) { _AccountBalance = AccountBalance; }

    // Getters
    string GetAccountNumber() const { return _AccountNumber; }
    string GetPinCode() const { return _PinCode; }
    double GetAccountBalance() const { return _AccountBalance; }

    void Print() const override
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << GetFullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient Find(const string& AccountNumber)
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

    static clsBankClient Find(const string& AccountNumber, const string& PinCode)
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

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enMode::EmptyMode: { return enSaveResults::svFaildEmptyObject; }

        case enMode::UpdateMode:
        {
            _Update(ClientsFileName);
            return enSaveResults::svSucceeded;
        }

        default:
            return enSaveResults::svFaildEmptyObject;

        }
    }

    static bool IsClientExist(const string& AccountNumber)
    {
        return (!Find(AccountNumber).IsEmpty());
    }

    static bool IsClientExist(const string& AccountNumber, const string& PinCode)
    {
        return (!Find(AccountNumber, PinCode).IsEmpty());
    }
};