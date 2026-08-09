#include <iostream>
#include "InputValidateLib.h"

using namespace std;

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
    cout << "Please Enter Client Data:-\n\n";
    ClientRecord.AccountNumber = InputValidateLib::ReadText("Enter Account Number?: ");
    ClientRecord.PinCode = InputValidateLib::ReadText("Enter PinCode?: ");
    ClientRecord.Name = InputValidateLib::ReadText("Enter Name?: ");
    ClientRecord.PhoneNumber = InputValidateLib::ReadText("Enter Phone?: ");
    ClientRecord.AccountBalance = InputValidateLib::ReadDblPositiveNumber("Enter Account Balance?: ");
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

int main()
{
    stClient ClientRecord = ReadNewClient();
    cout << "\n\nClient Record for saving is:-\n";
    cout << ConvertRecordToOneLine(ClientRecord, "#//#");
    return 0;
}