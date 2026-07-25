#include <iostream>
#include <vector>

using namespace std;

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

stClient ConvertLineDataToRecord(string Line, string Seperator)
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

void PrintClientRecord(stClient Client)
{
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone Number   : " << Client.PhoneNumber << endl;
    cout << "Account Balance: " << Client.AccountBalance;
}

int main()
{
    string Line = "AB23#//#5673#//#Abdullah Nori Shlgoom#//#0931364346#//#272.670013";
    stClient Client = ConvertLineDataToRecord(Line, "#//#");
    cout << "Line Record is:\n";
    cout << Line;
    cout << "\n\nThe following is the extracted client record:\n\n";
    PrintClientRecord(Client);
}