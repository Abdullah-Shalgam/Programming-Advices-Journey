#include <iostream>
#include <string>
#include <cctype>
#include "InputLib.h"

using namespace std;

char ReadLetter()
{
    char Character;
    cout << "\nPlease enter a Character?:\n";
    cin >> Character;
    return Character;
}

short CountCharacterInText(string Text, char c)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (Letter == c)
            Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = InputLib::ReadText("Please Enter Your stirng?:\n");
    char c = ReadLetter();
    cout << "letter '" << c <<"' Count = " << CountCharacterInText(S1, c);
    return 0;
}