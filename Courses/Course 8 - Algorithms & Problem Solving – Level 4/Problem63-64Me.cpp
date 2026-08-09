#include <iostream>
#include <string>
#include <vector>
#include "InputValidateLib.h"

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

stDate StringToDateStruct(string DateString, string Delim = "/")
{
    stDate DateStruct;
    short DateElements[4] = { 0, 0, 0, 0 };
    
    string sWord = "";
    short Counter = 1;

    for (char &c : DateString)
    {
        if (c == Delim[0])
        {
            if (!sWord.empty() && Counter <= 3)
            {
                DateElements[Counter] = stoi(sWord);
                Counter++;
                sWord = "";
            }
        }
        else
        {
            sWord += c;
        }
    }
    
    if (!sWord.empty() && Counter <= 3)
    {
        DateElements[Counter] = stoi(sWord);
    }

    DateStruct.Day   = DateElements[1];
    DateStruct.Month = DateElements[2];
    DateStruct.Year  = DateElements[3];

    return DateStruct;
}

string DateStructToString(stDate DateStruct, string Delim = "/")
{
    string DateString = "";

    DateString += to_string(DateStruct.Day) + Delim;
    DateString += to_string(DateStruct.Month) + Delim;
    DateString += to_string(DateStruct.Year);

    return DateString;
}

int main()
{
    string DateString = InputValidateLib::ReadText("Please Enter DateString dd/mm/yyyy : ");

    stDate DateStruct = StringToDateStruct(DateString);
    
    cout << "\nDay: " << DateStruct.Day;
    cout << "\nMonth: " << DateStruct.Month;
    cout << "\nYear: " << DateStruct.Year;

    cout << "\n\nYou Entered: " << DateStructToString(DateStruct);
}