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

/**
 * @class clsBankClient
 * @brief Core Domain Model representing a banking client.
 *
 * Handles bank client state, data persistence (CRUD operations via Flat-Files),
 * dynamic balance updates, transfers, and transfer logging.
 */
class clsBankClient : public clsPerson
{
public:
    // ----------------------------------------------------------
    // Data Structures & Enums
    // ----------------------------------------------------------

    struct stTransferLogRecord
    {
        std::string DateTime;
        std::string SenderAccountNumber;
        std::string DestinationAccountNumber;
        double Amount;
        double SenderBalanceAfter;
        double DestinationBalanceAfter;
        std::string UserName;
    };

    enum class enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };

    enum class enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

private:
    enMode _Mode;
    std::string _AccountNumber;
    std::string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;

    // Private Constructor for Object Factory Pattern
    clsBankClient(enMode Mode,
                  const std::string &FirstName,
                  const std::string &LastName,
                  const std::string &Email,
                  const std::string &Phone,
                  const std::string &AccountNumber,
                  const std::string &PinCode,
                  const double AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone),
          _Mode(Mode),
          _AccountNumber(AccountNumber),
          _PinCode(PinCode),
          _AccountBalance(AccountBalance)
    {
    }

    // ----------------------------------------------------------
    // Data Serialization & Parsing (Internal Helpers)
    // ----------------------------------------------------------

    static clsBankClient _ConvertLineToClientObject(const std::string &Line, const std::string &Separator = "#//#")
    {
        std::vector<std::string> vClientData = MyStringLib::SplitString(Line, Separator);

        if (vClientData.size() < 7)
            return _GetEmptyClientObject();

        std::string DecryptedPinCode = UtilLib::DecryptText(vClientData[5], Global::EncryptionKey);

        return clsBankClient(enMode::UpdateMode,
                             vClientData[0], vClientData[1], vClientData[2],
                             vClientData[3], vClientData[4], DecryptedPinCode,
                             std::stod(vClientData[6]));
    }

    static std::string _ConvertClientObjectToLine(const clsBankClient &Client, const std::string &Separator = "#//#")
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(6) << Client.GetAccountBalance();

        std::string EncryptedPinCode = UtilLib::EncryptText(Client.GetPinCode(), Global::EncryptionKey);

        return Client.GetFirstName() + Separator +
               Client.GetLastName() + Separator +
               Client.GetEmail() + Separator +
               Client.GetPhone() + Separator +
               Client.GetAccountNumber() + Separator +
               EncryptedPinCode + Separator +
               ss.str();
    }

    static std::vector<clsBankClient> _LoadClientsDataFromFile()
    {
        std::vector<clsBankClient> vClients;
        std::fstream MyFile(Global::ClientsFilePath, std::ios::in);

        if (MyFile.is_open())
        {
            std::string Line;
            while (std::getline(MyFile, Line))
            {
                if (!Line.empty())
                    vClients.push_back(_ConvertLineToClientObject(Line));
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientsDataToFile(const std::vector<clsBankClient> &vClients)
    {
        std::fstream MyFile(Global::ClientsFilePath, std::ios::out);
        if (MyFile.is_open())
        {
            for (const clsBankClient &Client : vClients)
            {
                if (!Client._MarkedForDelete)
                {
                    MyFile << _ConvertClientObjectToLine(Client) << "\n";
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(const std::string &DataLine)
    {
        std::fstream MyFile(Global::ClientsFilePath, std::ios::out | std::ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << "\n";
            MyFile.close();
        }
    }

    void _Update()
    {
        std::vector<clsBankClient> vClients = _LoadClientsDataFromFile();

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
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    bool _MarkForDelete(std::vector<clsBankClient> &vClients)
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

    // ----------------------------------------------------------
    // Audit & Transfer Log Helpers
    // ----------------------------------------------------------

    std::string _PrepareTransferLog(const double Amount, const clsBankClient &DestinationClient, const std::string &UserName, const std::string &Separator = "#//#") const
    {
        std::ostringstream ssAmount, ssSenderBal, ssDestBal;

        ssAmount << std::fixed << std::setprecision(6) << Amount;
        ssSenderBal << std::fixed << std::setprecision(6) << GetAccountBalance();
        ssDestBal << std::fixed << std::setprecision(6) << DestinationClient.GetAccountBalance();

        return UtilLib::GetSystemDateTime() + Separator +
               GetAccountNumber() + Separator +
               DestinationClient.GetAccountNumber() + Separator +
               ssAmount.str() + Separator +
               ssSenderBal.str() + Separator +
               ssDestBal.str() + Separator +
               UserName;
    }

    void _RegisterTransferLog(const double Amount, const clsBankClient &DestinationClient, const std::string &UserName)
    {
        std::fstream MyFile(Global::TransferLogFilePath, std::ios::out | std::ios::app);
        if (MyFile.is_open())
        {
            MyFile << _PrepareTransferLog(Amount, DestinationClient, UserName) << "\n";
            MyFile.close();
        }
    }

    static stTransferLogRecord _ConvertTransferLogLineToRecord(const std::string &Line, const std::string &Separator = "#//#")
    {
        std::vector<std::string> vData = MyStringLib::SplitString(Line, Separator);

        if (vData.size() < 7)
            return {};

        return {vData[0], vData[1], vData[2], std::stod(vData[3]), std::stod(vData[4]), std::stod(vData[5]), vData[6]};
    }

    static std::vector<stTransferLogRecord> _LoadTransferLogDataFromFile()
    {
        std::vector<stTransferLogRecord> vRecords;
        std::fstream MyFile(Global::TransferLogFilePath, std::ios::in);

        if (MyFile.is_open())
        {
            std::string Line;
            while (std::getline(MyFile, Line))
            {
                if (!Line.empty())
                    vRecords.push_back(_ConvertTransferLogLineToRecord(Line));
            }
            MyFile.close();
        }
        return vRecords;
    }

public:
    // Status Queries
    bool IsEmpty() const { return (_Mode == enMode::EmptyMode); }
    bool IsMarkedForDelete() const { return _MarkedForDelete; }

    // Setters & Getters
    void SetPinCode(const std::string &PinCode) { _PinCode = PinCode; }
    void SetAccountBalance(const double AccountBalance) { _AccountBalance = AccountBalance; }

    std::string GetAccountNumber() const { return _AccountNumber; }
    std::string GetPinCode() const { return _PinCode; }
    double GetAccountBalance() const { return _AccountBalance; }

    // ----------------------------------------------------------
    // Public Static Operations (Data Access Layer)
    // ----------------------------------------------------------

    static clsBankClient Find(const std::string &AccountNumber)
    {
        std::fstream MyFile(Global::ClientsFilePath, std::ios::in);

        if (MyFile.is_open())
        {
            std::string line;
            while (std::getline(MyFile, line))
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

    static clsBankClient Find(const std::string &AccountNumber, const std::string &PinCode)
    {
        clsBankClient Client = Find(AccountNumber);

        if (!Client.IsEmpty() && Client.GetPinCode() == PinCode)
            return Client;

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(const std::string &AccountNumber)
    {
        return (!Find(AccountNumber).IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(const std::string &AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static std::vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        std::vector<clsBankClient> vClients = GetClientsList();
        double TotalBalances = 0;
        for (const clsBankClient &Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }
        return TotalBalances;
    }

    static std::vector<stTransferLogRecord> GetTransferLogList()
    {
        return _LoadTransferLogDataFromFile();
    }

    // ----------------------------------------------------------
    // Public Business Logic API
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
        if (Amount <= 0)
            return false;

        _AccountBalance += Amount;
        return (Save() == enSaveResults::svSucceeded);
    }

    bool Withdraw(double Amount)
    {
        if (Amount <= 0 || Amount > _AccountBalance)
            return false;

        _AccountBalance -= Amount;
        return (Save() == enSaveResults::svSucceeded);
    }

    bool Transfer(double Amount, clsBankClient &DestinationClient, const std::string &UserName)
    {
        if (Amount <= 0 || Amount > _AccountBalance)
            return false;

        if (!Withdraw(Amount))
        {
            return false;
        }

        if (!DestinationClient.Deposit(Amount))
        {
            Deposit(Amount); // Rollback
            return false;
        }

        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    bool Delete()
    {
        if (IsEmpty())
            return false;

        std::vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        if (_MarkForDelete(vClients))
        {
            _SaveClientsDataToFile(vClients);
            *this = _GetEmptyClientObject();
            return true;
        }
        return false;
    }
};