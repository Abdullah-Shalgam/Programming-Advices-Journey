#include <iostream>
#include <fstream>
#include <vector>
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

stClient ReadNewClient()
{
    stClient ClientRecord;
    ClientRecord.AccountNumber = InputLib::ReadText("Enter Account Number?: ");
    ClientRecord.PinCode = InputLib::ReadText("Enter PinCode?: ");
    ClientRecord.Name = InputLib::ReadText("Enter Name?: ");
    ClientRecord.PhoneNumber = InputLib::ReadText("Enter Phone?: ");
    ClientRecord.AccountBalance = InputLib::ReadFloatPositiveNumber("Enter Account Balance?: ");
    return ClientRecord;
}

string ConvertRecordToOneLine(stClient &Record, string Seperator)
{
    string Result = "";
    Result += Record.AccountNumber + Seperator;
    Result += Record.PinCode + Seperator;
    Result += Record.Name + Seperator;
    Result += Record.PhoneNumber + Seperator;
    Result += to_string(Record.AccountBalance);
    return Result;
}

void SaveClientsVectorToFile(string FileName, vector<stClient> &vClients, string Seperator)
{
    fstream File;
    File.open(FileName, ios::out | ios::app); 
    if (File.is_open())
    {
        for (stClient &Client : vClients)
        {
            File << ConvertRecordToOneLine(Client, Seperator);
            cout << "\n";
        }
        File.close();
    }
}

void ResetTheScreen()
{
    system("color 0F");
    system("cls");
}

void AddNewClients()
{
    vector<stClient> vClients;
    char AddNew = ' ';
    do
    {
        ResetTheScreen();
        cout << "Adding New Client:-\n\n";
        stClient Client = ReadNewClient();
        vClients.push_back(Client);
        cout << "\nClient Added Successfully, do you want to add more clients?: ";
        cin >> AddNew;
    } while (toupper(AddNew) == 'Y');
    if (!vClients.empty()) {
        SaveClientsVectorToFile(ClientsFileName, vClients, "#//#");
    }
}

int main()
{
    AddNewClients();
    return 0;
}
