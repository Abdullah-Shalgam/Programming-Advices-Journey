#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

short CountWordsInText(string Text)
{
    char Delim = ' ';
    string sWord = "";
    short Pos = 0;
    short Counter = 0;
    while ((Pos = Text.find(Delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        if (sWord != "")
        {
            Counter++;
        }
        Text.erase(0, Pos + 1);
    }
    if (Text != "")
    {
        Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    cout << endl;
    cout << "The number of words in your string is: " << CountWordsInText(S1);
    return 0;
}