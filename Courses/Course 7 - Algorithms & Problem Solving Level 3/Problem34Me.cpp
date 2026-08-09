#include <iostream>
#include "InputValidateLib.h"

using namespace std;

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void PrintVowelsInText(string Text)
{
    cout << "Vowels in string are: ";
    for (const char &Letter : Text)
    {
        if (IsVowel(Letter))
            cout << Letter << "   ";
    }
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your String?:\n");
    cout << endl;
    PrintVowelsInText(S1);
    return 0;
}