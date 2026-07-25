#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

enum enCharType { SmallCharacter = 1, CapitalCharacter = 2, SpecialCharacter = 3, Digit = 4 };

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num > 0)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
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

string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int i = 1; i <= Length; i++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";
    for (int i = 1; i <= 4; i++)
    {
        Key += GenerateWord(enCharType::CapitalCharacter, 4);
        if (i != 4) Key += '-';
    }
    return Key;
}

void FillArrayWithKeys(string Array [100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
        Array [i] = GenerateKey();
}

void PrintStringArray(string Array [100], int ArrayLength)
{
    cout << "\nArray elements: \n";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Array [" << i << "] : " << Array [i] << "\n";
    }
}

int main()
{
    srand(time(0));
    const int MAX_SIZE = 100;
    string Array[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many keys you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    FillArrayWithKeys(Array, ArrayLength);
    PrintStringArray(Array, ArrayLength);
    return 0;
}