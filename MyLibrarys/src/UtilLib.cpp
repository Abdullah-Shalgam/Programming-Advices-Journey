#include "UtilLib.h"

using namespace std;

void UtilLib::Srand()
{
    srand((unsigned)time(NULL));
}

string UtilLib::Tabs(int Count)
{
    string t = "";
    for (int j = 1; j <= Count; j++)
    {
        t += "\t";
    }
    return t;
}

void UtilLib::ResetTheScreen()
{
    system("color 0F");
    system("cls");
}

string UtilLib::EncryptText(string Text, short EncryptionKey)
{
    for (size_t i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

string UtilLib::DecryptionText(string Text, short EncryptionKey)
{
    for (size_t i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int UtilLib::RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char UtilLib::GetRandomCharacter(enCharType CharType)
{
    if (CharType == enCharType::MixChars)
    {
        CharType = (enCharType)RandomNumber(1, 3);
    }

    switch (CharType)
    {
    case enCharType::SmallCharacter:
        return char(RandomNumber(97, 122));
    case enCharType::CapitalCharacter:
        return char(RandomNumber(65, 90));
    case enCharType::SpecialCharacter:
    {
        int SpecialCharacterRange = RandomNumber(1, 4);
        if (SpecialCharacterRange == 1) return char(RandomNumber(33, 47));
        if (SpecialCharacterRange == 2) return char(RandomNumber(58, 64));
        if (SpecialCharacterRange == 3) return char(RandomNumber(91, 96));
        return char(RandomNumber(123, 126));
    }
    case enCharType::Digit:
        return char(RandomNumber(48, 57));
    default:
        return '\0';
    }
}

string UtilLib::GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (short i = 1; i <= Length; i++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string UtilLib::GenerateKey(enCharType CharType)
{
    string Key = "";
    for (short i = 1; i <= 4; i++)
    {
        Key += GenerateWord(CharType, 4);
        if (i != 4) Key += '-';
    }
    return Key;
}

void UtilLib::GenerateKeys(short NumberOfKeys, enCharType CharType)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] \t: " << GenerateKey(CharType) << "\n";
    }
}

void UtilLib::FillArrayWithRandomNumbers(int Array[], int ArrayLength, int From, int To)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(From, To);
    }
}

void UtilLib::FillArrayWithRandomWords(string Array[], int ArrayLength, enCharType CharType, short Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateWord(CharType, Length);
    }
}

void UtilLib::FillArrayWithRandomKeys(string Array[], int ArrayLength, enCharType CharType)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateKey(CharType);
    }
}