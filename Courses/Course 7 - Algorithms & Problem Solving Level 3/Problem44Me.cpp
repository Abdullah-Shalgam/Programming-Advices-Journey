#include <iostream>
#include "InputValidateLib.h"

using namespace std;

string DeleteAllPunctuationsFromText(string S1)
{
    string Reslut = "";
    for (const char &Character : S1)
    {
        if (!ispunct(Character))
        {
            Reslut += Character;
        }
    }
    return Reslut;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    cout << "\nString After Delete All Punctuations:-\n";
    cout << DeleteAllPunctuationsFromText(S1);
    return 0;
}