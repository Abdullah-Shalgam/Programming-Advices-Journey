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

string MakeTextLowerCase(string Text)
{
    string Word = "";
    for (int i = 0; i <= Text.length() - 1; i++)
    {
        Word += tolower(Text[i]);
    }
    return Word;
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enCharType CheckUserSelection(string UserChoice)
{
    while (true)
    {
        if (MakeTextLowerCase(UserChoice) == "small letter")
            return enCharType::SmallCharacter;
        else if (MakeTextLowerCase(UserChoice) == "capital letter")
            return enCharType::CapitalCharacter;
        else if (MakeTextLowerCase(UserChoice) == "special letter")
            return enCharType::SpecialCharacter;
        else if (MakeTextLowerCase(UserChoice) == "digit")
            return enCharType::Digit;
        else
        {
            cout << "Invalid Input!\n";
            UserChoice = ReadText("Choose randomly if you want (digit/capital letter/small letter/special letter): ");
        }
    }
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
    string Input = ReadText("Choose randomly (digit/capital letter/small letter/special letter): ");
    enCharType UserSelection = CheckUserSelection(Input);
    cout << "Your Random Character is: " << GetRandomCharacter(UserSelection) << endl;
    return 0;
}