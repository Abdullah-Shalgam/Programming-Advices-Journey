#include <iostream>
#include <string>
#include <cctype>
#include "InputValidateLib.h"

using namespace std;

char ReadLetter()
{
    char Character;
    cout << "\nPlease enter a Character?:\n";
    cin >> Character;
    return Character;
}

char InvertCharacterCase(char c)
{
    return (islower(c)) ? toupper(c) : tolower(c);
}

short CountCharacterInText(string Text, char c, bool MatchCase = true)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (MatchCase)
        {
            if (Letter == c)
                Counter++;
        }
        else
        {
            if (tolower(Letter) == tolower(c))
                Counter++;
        }
    }
    return Counter;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your stirng?:\n");
    char c = ReadLetter();
    cout << "\nletter '" << c <<"' Count = " << CountCharacterInText(S1, c);
    cout << "\nletter '" << c << "' Or '" << InvertCharacterCase(c) << "' Count = " << CountCharacterInText(S1, c, false);
    return 0;
}
