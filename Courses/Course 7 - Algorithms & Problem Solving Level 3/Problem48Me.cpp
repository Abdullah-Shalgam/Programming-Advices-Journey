#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <iomanip>

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

void PrintClientRecord(const stClient &Client)
{
    cout << "\n";
    cout << "| " << left << setw(15) << Client.AccountNumber << "| " << left << setw(9) << Client.PinCode << "| " << left << setw(55) << Client.Name << "| " << left << setw(13) << Client.PhoneNumber << "| " << left << setw(13) << Client.AccountBalance << "|";
}

void DisplayClientsList(vector<stClient> vClientRecord)
{
    cout << setw(116) << "Client List (" + to_string(vClientRecord.size()) + ") Client(s).                                             \n";
    cout << "____________________________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number" << "| " << left << setw(9) << "Pin Code" << "| " << left << setw(55) << "Client Name" << "| " << left << setw(13) << "Phone" << "| " << left << setw(13) << "Balance" << "|";
    cout << "\n____________________________________________________________________________________________________________________\n";
    for (const stClient &Record : vClientRecord)
    {
        PrintClientRecord(Record);
    }
    cout << "\n____________________________________________________________________________________________________________________";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <stClient> vClientRecord = LoadFillContentToVector(ClientsFileName);
    DisplayClientsList(vClientRecord);
    return 0;
}