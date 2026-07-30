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

string FormatDate(string DateString, string FormatType, string Delim, bool IsSperatedDate = false)
{
    string FormatedDate = "";
    stDate DateStruct = StringToDateStruct(DateString);

    vector <string> vFomat = SplitText(FormatType, "/"); 

    if (!IsSperatedDate)
    {
        for (short i = 0; i < vFomat.size(); i++)
        {
            if (vFomat[i] == "dd")   FormatedDate += to_string(DateStruct.Day) + Delim;
            if (vFomat[i] == "mm")   FormatedDate += to_string(DateStruct.Month) + Delim;
            if (vFomat[i] == "yyyy") FormatedDate += to_string(DateStruct.Year) + Delim;
        }

        if (FormatedDate.length() >= Delim.length())
            return FormatedDate.substr(0, (FormatedDate.length() - Delim.length()));
    }
    else
    {
        for (short i = 0; i < vFomat.size(); i++)
        {
            if (vFomat[i] == "dd")   FormatedDate += "Day:" + to_string(DateStruct.Day) + ", ";
            if (vFomat[i] == "mm")   FormatedDate += "Month:" + to_string(DateStruct.Month) + ", ";
            if (vFomat[i] == "yyyy") FormatedDate += "Year:" + to_string(DateStruct.Year) + ", ";
        }

        if (FormatedDate.length() >= 2)
            return FormatedDate.substr(0, (FormatedDate.length() - 2)); 
    }

    return FormatedDate;
}

int main()
{
    string DateString = InputLib::ReadText("Please Enter DateString dd/mm/yyyy : ");
    cout << "\n";

    cout << FormatDate(DateString, "dd/mm/yyyy", "/");
    cout << "\n\n";

    cout << FormatDate(DateString, "yyyy/dd/mm", "/");
    cout << "\n\n";

    cout << FormatDate(DateString, "mm/dd/yyyy", "/");
    cout << "\n\n";

    cout << FormatDate(DateString, "mm/dd/yyyy", "-");
    cout << "\n\n";

    cout << FormatDate(DateString, "dd/mm/yyyy", "-");
    cout << "\n\n";

    cout << FormatDate(DateString, "dd/mm/yyyy", "/", true);
    cout << "\n\n";
}