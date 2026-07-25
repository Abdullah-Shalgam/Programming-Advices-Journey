
#include <iostream>
#include <string>
#include <vector>

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

string ReplaceWordInString1(string S1, string StringWantToReplace, string StringToReplace)
{
    short Pos = 0;
    string sWord = "";
    while ((Pos = S1.find(StringWantToReplace)) != string::npos)
    {
        sWord += S1.substr(0, Pos) + StringToReplace;
        S1 = S1.substr(Pos + StringWantToReplace.length());
    }
    if (S1 != "")
    {
        sWord += S1;
    }
    return sWord;
}

string ReplaceWordInString2(string S1, string StringWantToReplace, string StringToReplace)
{
    vector <string> vText = SplitText(S1);
    for (string &Word : vText)
    {
        if (Word == StringWantToReplace)
        {
            Word = StringToReplace;
        }
    }
    return JoinText(vText, " ");
}

string ReplaceWordInString3(string S1, string StringWantToReplace, string StringToReplace)
{
    string sWord = "";
    vector <string> vText = SplitText(S1);
    for (const string &Word : vText)
    {
        if (Word == StringWantToReplace)
        {
            sWord += StringToReplace + " ";
        }
        else
        {
            sWord += Word + " ";
        }
    }
    return sWord.substr(0, sWord.length() - 1);
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "Original String:-\n";
    cout << S1;
    cout << "\n\nString After Replace:-\n";
    cout << ReplaceWordInString1(S1, "Jordan", "USA");
    return 0;
}