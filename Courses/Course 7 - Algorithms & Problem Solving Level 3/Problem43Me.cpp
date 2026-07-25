#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "MyStringLib.h"

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

string JoinText(const vector <string> &vText, string Delim = " ")
{
    string sWord = "";
    for (const string &Word : vText)
    {
        sWord += Word + Delim;
    }
    return sWord.substr(0, (sWord.length() - Delim.length()));
}

string ReplaceWordInString1(string S1, string StringWantToReplace, string StringToReplace, bool MatchCase = true)
{
    vector <string> vText = SplitText(S1, " ");
    string TargetWordLower = (MatchCase) ? "" : MyStringLib::ConvertTextToLowerCase(StringWantToReplace);
    for (string &Word : vText)
    {
        if ((MatchCase) ? (Word == StringWantToReplace) : (MyStringLib::ConvertTextToLowerCase(Word) == TargetWordLower))
        {
            Word = StringToReplace;
        }
    }
    return JoinText(vText, " ");
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "Original String:-\n";
    cout << S1;
    cout << "\n\nString After Replace With Match Case:-\n";
    cout << ReplaceWordInString1(S1, "jordan", "USA");
    cout << "\n\nString After Replace Wthout Match Case:-\n";
    cout << ReplaceWordInString1(S1, "jordan", "USA", false);
    return 0;
}