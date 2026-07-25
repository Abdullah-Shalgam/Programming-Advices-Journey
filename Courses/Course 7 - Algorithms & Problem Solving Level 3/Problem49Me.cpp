#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <iomanip>
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
    ClientRecords.AccountBalance = stoi(vClientData[4]);
    
    return ClientRecords;
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

bool FindClientByAccountNumber(string AccountNumber, stClient &Client)
{
    vector <stClient> vClientRecord = LoadFillContentToVector(ClientsFileName);
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

int main()
{
    stClient Client;
    string AccountNumber = InputLib::ReadText("Please Enter Account Number?: ");
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientDetails(Client);
    }
    else
    {
        printf("\nClient With Account Number (%s) Not Found!.", AccountNumber.c_str());
    }
    return 0;
}