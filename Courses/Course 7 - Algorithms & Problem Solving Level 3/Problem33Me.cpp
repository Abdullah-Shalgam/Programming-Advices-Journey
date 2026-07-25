#include <iostream>
#include "InputLib.h"

using namespace std;

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

short CountVowelsInText(string Text)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (IsVowel(Letter))
            Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = InputLib::ReadText("Please Enter Your String?:\n");
    cout << endl;
    cout << "Number of Vowels is: " << CountVowelsInText(S1);
    return 0;
}