#include <iostream>
#include "InputLib.h"
#include "MyStringLib.h"

using namespace std;

void PrintEachWordFromText1(string Text)
{
    cout << "Your string words are:\n\n";
    string Word = "";
    for (const char &Letter : Text)
    {
        if (Letter != ' ')
        {
            Word += Letter;
        }
        if (Letter == ' ' || Letter == Text[Text.length() - 1])
        {
            cout << Word << endl;
            Word = "";
        }
    }
}

void PrintEachWordFromText2(string Text)
{
    cout << "Your string words are:\n\n";
    for (const char &Letter : Text)
    {
        if (Letter != ' ')
        {
            cout << Letter;
            continue;
        }
        if (Letter == ' ')
        {
            cout << endl;
        }
    }
}

int main()
{
    string S1 = InputLib::ReadText("Please Enter Your Stirng?:\n");
    cout << endl;
    PrintEachWordFromText2(S1);
    return 0;
}