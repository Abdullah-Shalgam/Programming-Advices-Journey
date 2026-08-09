#include <iostream>
#include <string>
#include <vector>
#include "InputValidateLib.h"

using namespace std;

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

string ReverseWordInString(string S1)
{
    string sWord = "";
    vector <string> vText = SplitText(S1);
    vector <string>::iterator iter = vText.end();
    while (iter != vText.begin())
    {
        iter--;
        sWord += *iter + " ";
    }
    return sWord.substr(0, sWord.length() - 1);
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    cout << "\nString after reversing words:-\n";
    cout << ReverseWordInString(S1);
    return 0;
}