#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
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

stDate StringToDateStruct(string DateString, string Delim = "/")
{
    stDate DateStruct;
    vector <string> vDate;

    vDate = SplitText(DateString, Delim);

    DateStruct.Day = stoi(vDate[0]);
    DateStruct.Month = stoi(vDate[1]);
    DateStruct.Year = stoi(vDate[2]);

    return DateStruct;
}

string DateStructToString(stDate DateStruct, string Delim = "/")
{
    return to_string(DateStruct.Day) + Delim + to_string(DateStruct.Month) + Delim + to_string(DateStruct.Year);
}

int main()
{
    string DateString = InputLib::ReadText("Please Enter DateString dd/mm/yyyy : ");

    stDate DateStruct = StringToDateStruct(DateString);
    
    cout << "\nDay: " << DateStruct.Day;
    cout << "\nMonth: " << DateStruct.Month;
    cout << "\nYear: " << DateStruct.Year;

    cout << "\n\nYou Entered: " << DateStructToString(DateStruct);
}