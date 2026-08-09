#include <iostream>
#include <string>
#include "InputValidateLib.h"
#include "MyStringLib.h"

using namespace std;

void PrintEachWordInString(string Text)
{
    string delim = " ";
    short Pos = 0;
    string sWord = "";
    while ((Pos = Text.find(delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        Text.erase(0, Pos + 1);
    }
    if (Text != "")
    {
        cout << Text;
    }
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    cout << endl;
    PrintEachWordInString(S1);
    return 0;
}