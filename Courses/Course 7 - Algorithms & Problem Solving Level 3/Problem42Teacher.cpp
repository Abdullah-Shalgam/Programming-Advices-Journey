#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReplaceWordInString(string S1, string StringWantToReplace, string StringToReplace)
{
    short Pos = 0;

    while ((Pos = S1.find(StringWantToReplace, Pos)) != string::npos)
    {
        S1.replace(Pos, StringWantToReplace.length(), StringToReplace);
        Pos += StringToReplace.length();
    }
    return S1;
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "Original String:-\n";
    cout << S1;
    cout << "\n\nString After Replace:-\n";
    cout << ReplaceWordInString(S1, "Jordan", "USA");
    return 0;
}