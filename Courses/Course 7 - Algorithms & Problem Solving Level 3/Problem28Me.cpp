#include <iostream>
#include <string>
#include <cctype>
#include "InputValidateLib.h"

using namespace std;

char InvertCharacterCase(char c)
{
    return (islower(c)) ? toupper(c) : tolower(c);
}

string InvertTextCase(string Text)
{
    for (char &Letter : Text)
    {
        Letter = InvertCharacterCase(Letter);
    }
    return Text;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your stirng?:\n");
    cout << "\nString after Inverting All Letters Case:\n";
    S1 = InvertTextCase(S1);
    cout << S1;
    return 0;
}