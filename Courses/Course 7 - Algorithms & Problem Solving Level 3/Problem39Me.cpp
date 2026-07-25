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

int main()
{
    string S1 = "Mohammed---Ahmed---Khalid---Ali---Abdullah.";
    string Delim = "---";
    vector <string> vText;
    vText = SplitText(S1, Delim);
    cout << "Vector Elements:-\n\n";
    for (const string &Word : vText)
    {
        cout << Word << endl;
    }
    cout << "\nPrint Join Vector Using (--):-\n\n";
    cout << JoinText(vText, "--");
    return 0;
}