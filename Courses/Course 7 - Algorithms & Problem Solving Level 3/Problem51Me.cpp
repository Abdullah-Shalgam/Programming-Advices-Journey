#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include "InputLib.h"

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber  = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    double AccountBalance = 0;
    bool MarkForDelete = false;
};

vector <string> SplitText(string Text, string Delim = " ")
{
    vector <string> vSpText;
    string sWord = "";
    short Pos = 0;
    while ((Pos = Text.find(Delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        if (sWord != "")
        {
            vSpText.push_back(sWord);
        }
        Text.erase(0, Pos + Delim.length());
    }
    if (Text != "")
    {
        vSpText.push_back(Text);
    }
    return vSpText;
}

stClient GetClientRecord(string Line, string Seperator = "#//#")
{
    stClient ClientRecords;
    vector <string> vClientData = SplitText(Line, Seperator);

    ClientRecords.AccountNumber = vClientData[0];
    ClientRecords.PinCode = vClientData[1];
    ClientRecords.Name = vClientData[2];
    ClientRecords.PhoneNumber = vClientData[3];
    ClientRecords.AccountBalance = stod(vClientData[4]);
    
    return ClientRecords;
}

string ConvertRecordToOneLine(stClient &Record, string Seperator = "#//#")
{
    ostringstream ss;
    ss << fixed << setprecision(6) << Record.AccountBalance; 
    
    string Result = "";
    Result += Record.AccountNumber + Seperator;
    Result += Record.PinCode + Seperator;
    Result += Record.Name + Seperator;
    Result += Record.PhoneNumber + Seperator;
    Result += ss.str();
    
    return Result;
}

vector<stClient> LoadFillContentToVector(string FileName)
{
    vector <stClient> vFileContent;
    fstream Fill;
    Fill.open(FileName, ios::in);
    if (Fill.is_open())
    {
        string Line;
        while(getline(Fill, Line))
        {
            if (Line != "")
                vFileContent.push_back(GetClientRecord(Line));
        }
        Fill.close();
    }
    return vFileContent;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> &vClientRecord, stClient &Client)
{
    for (const stClient &Record : vClientRecord)
    {
        if (Record.AccountNumber == AccountNumber)
        {
            Client = Record;
            return true;
        }
    }
    return false;
}

void PrintClientDetails(stClient Client)
{
    cout << "\nThe following are the client details:-\n\n";
    cout << "Account Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name;
    cout << "\nPhone Number   : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n";
    cout << endl;
}

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

    Client.AccountNumber = AccountNumber;
    Client.PinCode = InputLib::ReadText("Enter PinCode?: ");
    Client.Name = InputLib::ReadText("Enter Name?: ");
    Client.PhoneNumber = InputLib::ReadText("Enter Phone?: ");
    Client.AccountBalance = InputLib::ReadFloatPositiveNumber("Enter Account Balance?: ");

    return Client;
}

bool SaveCleintsDataToFile(string FileName, vector<stClient> &vClientRecord)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        string DataLine = "";
        for (stClient &Client : vClientRecord)
        {
            if (!Client.MarkForDelete)
            {
                DataLine = ConvertRecordToOneLine(Client);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
        return true;
    }
    return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient> &vClientRecord)
{
    char Answer = 'n';
    stClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClientRecord, Client))
    {
        PrintClientDetails(Client);
        Answer = InputLib::ReadCharacter("Are you sure you want update this client? (y/n): ");
        if (tolower(Answer) == 'y')
        {
            cout << "\n\n";
            for (stClient &C : vClientRecord)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClientRecord);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
        return false;
    }
    else
    {
        printf("\nClient With Account Number (%s) Not Found!.", AccountNumber.c_str());
        return false;
    }
}

int main()
{
    vector <stClient> vClientRecord = LoadFillContentToVector(ClientsFileName);
    string AccountNumber = InputLib::ReadText("Please Enter Account Number?: ");
    
    UpdateClientByAccountNumber(AccountNumber, vClientRecord);

    return 0;
}