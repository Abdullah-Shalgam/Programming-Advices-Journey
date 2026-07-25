#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

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

int main()
{
    string S1 = InputLib::ReadText("Please Enter Your Stirng?:\n");
    string Delim = InputLib::ReadText("Please Enter the split Delimiter?:\n");
    vector <string> vSpText;
    vSpText = SplitText(S1, Delim);
    cout << "Tokken = " << vSpText.size() << endl;
    for (const string &Word : vSpText)
    {
        cout << Word << endl;
    }
    return 0;
}