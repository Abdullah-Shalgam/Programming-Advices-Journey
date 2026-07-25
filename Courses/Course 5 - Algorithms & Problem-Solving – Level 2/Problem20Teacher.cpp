#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

enum enCharType { SmallCharacter = 1, CapitalCharacter = 2, SpecialCharacter = 3, Digit = 4 };

string ReadText(string Msg)
{
    string Text;
    cout << Msg;
    getline(cin, Text);
    return Text;
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType Selection)
{
    switch (Selection)
    {
    case enCharType::SmallCharacter:
        return char(RandomIntNumber(97, 122));
    case enCharType::CapitalCharacter:
        return char(RandomIntNumber(65, 90));
    case enCharType::SpecialCharacter:
        {
            int SpecialCharacterRange = RandomIntNumber(1, 4);
            if (SpecialCharacterRange == 1) return char(RandomIntNumber(33, 47));
            if (SpecialCharacterRange == 2) return char(RandomIntNumber(58, 64));
            if (SpecialCharacterRange == 3) return char(RandomIntNumber(91, 96));
            return char(RandomIntNumber(123, 126));
        }
    case enCharType::Digit:
        return char(RandomIntNumber(48, 57));
    default:
        return '\0';
    }
}

int main()
{
    srand(time(0));
    
    cout << GetRandomCharacter(enCharType::CapitalCharacter) << "\n";
    cout << GetRandomCharacter(enCharType::SmallCharacter) << "\n";
    cout <<GetRandomCharacter(enCharType::SpecialCharacter) << "\n";
    cout << GetRandomCharacter(enCharType::Digit);
    return 0;
}