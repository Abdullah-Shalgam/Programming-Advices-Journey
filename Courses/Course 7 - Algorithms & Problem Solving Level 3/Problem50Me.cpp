#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include "InputValidateLib.h"

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber  = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    double AccountBalance = 0;
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

vector<stClient> LoadFillContentTostClientVector(string FileName)
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

vector<string> LoadFillContentToStringVector(string FileName)
{
    vector <string> vFileContent;
    fstream Fill;
    Fill.open(FileName, ios::in);
    if (Fill.is_open())
    {
        string Line;
        while(getline(Fill, Line))
        {
            if (Line != "")
                vFileContent.push_back(Line);
        }
        Fill.close();
    }
    return vFileContent;
}

void LoadDataFromVectorToFile(string FillName, const vector <string> &vFillContent)
{
    fstream MyFile;
    MyFile.open(FillName, ios::out);
    if (MyFile.is_open())
    {
        for (const string &Line : vFillContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

bool FindClientByAccountNumber(string AccountNumber, stClient &Client)
{
    vector <stClient> vClientRecord = LoadFillContentTostClientVector(ClientsFileName);
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

void DeleteClientByAccountNumber(string AccountNumber)
{
    stClient Client;
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        vector <string> vDataLines = LoadFillContentToStringVector(ClientsFileName);
        for (string &vLine : vDataLines)
        {
            if (vLine != "")
            {
                vector <string> vClientData = SplitText(vLine, "#//#");
                if (vClientData[0] == AccountNumber)
                {
                    vLine = "";
                    break;
                }
            }
            
        }
        LoadDataFromVectorToFile(ClientsFileName, vDataLines);
        cout << "\n\nClient Deleted Successfully.";
    }
    else
    {
        printf("\nClient With Account Number (%s) Not Found!.", AccountNumber.c_str());
    }
}

bool IsWantDelete()
{
    char Answer = InputValidateLib::ReadCharacter("Are you sure you want delete this client? (y/n): ");
    return (tolower(Answer) == 'y');
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

int main()
{
    stClient Client;
    string AccountNumber = InputValidateLib::ReadText("Please Enter Account Number?: ");

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientDetails(Client);
        if (IsWantDelete())
        {
            DeleteClientByAccountNumber(AccountNumber);
        }
    }
    else
    {
        printf("\nClient With Account Number (%s) Not Found!.", AccountNumber.c_str());
    }
    return 0;
}