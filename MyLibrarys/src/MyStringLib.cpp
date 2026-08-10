#include "MyStringLib.h"

using namespace std;

// ===================================================
// PRIVATE HELPER METHODS
// ===================================================
short MyStringLib::_CountLetters(const string& Str, _enWhatToCount WhatToCount)
{
    short Counter = 0;

    for (const char& Letter : Str)
    {
        if (WhatToCount == _enWhatToCount::All && isalpha((unsigned char)Letter))
            Counter++;
        else if (WhatToCount == _enWhatToCount::CapitalLetters && isupper((unsigned char)Letter))
            Counter++;
        else if (WhatToCount == _enWhatToCount::SmallLetters && islower((unsigned char)Letter))
            Counter++;
    }

    return Counter;
}

// ===================================================
// 1. CONSTRUCTORS
// ===================================================
MyStringLib::MyStringLib() 
{ 
    _Value = ""; 
}

MyStringLib::MyStringLib(const string& Value) 
{ 
    _Value = Value; 
}

// ===================================================
// 2. SETTERS & GETTERS
// ===================================================
void MyStringLib::SetValue(const string& Value) 
{ 
    _Value = Value; 
}

string MyStringLib::GetValue() const 
{ 
    return _Value; 
}

// ===================================================
// 3. STATIC UTILITY METHODS
// ===================================================
string MyStringLib::LowerAllString(string Text)
{
    for (char &Letter : Text) 
        Letter = tolower((unsigned char)Letter);
    return Text;
}

string MyStringLib::CapitalizeAllString(string Text)
{
    for (char &Letter : Text) 
        Letter = toupper((unsigned char)Letter);
    return Text;
}

char MyStringLib::InvertCharacterCase(char c)
{
    return (islower((unsigned char)c)) ? toupper((unsigned char)c) : tolower((unsigned char)c);
}

string MyStringLib::InvertAllLettersCase(string Text)
{
    for (char &Letter : Text)
        Letter = InvertCharacterCase(Letter);
    return Text;
}

string MyStringLib::CapitalizeFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
            Text[i] = toupper((unsigned char)Text[i]);
        IsFirstLetter = (Text[i] == ' ');
    }
    return Text;
}

string MyStringLib::LowerFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
            Text[i] = tolower((unsigned char)Text[i]);
        IsFirstLetter = (Text[i] == ' ');
    }
    return Text;
}

short MyStringLib::CountLength(const string& Text)
{
    return Text.length();
}

short MyStringLib::CountAllLetters(const string& Text)
{
    return _CountLetters(Text, _enWhatToCount::All);
}

short MyStringLib::CountLowerCaseLetters(const string& Text)
{
    return _CountLetters(Text, _enWhatToCount::SmallLetters);
}

short MyStringLib::CountUpperCaseLetters(const string& Text)
{
    return _CountLetters(Text, _enWhatToCount::CapitalLetters);
}

short MyStringLib::CountSpecificCharacter(const string& Text, char CharacterToCount, bool MatchCase)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (MatchCase)
        {
            if (Letter == CharacterToCount) Counter++;
        }
        else
        {
            if (tolower((unsigned char)Letter) == tolower((unsigned char)CharacterToCount)) Counter++;
        }
    }
    return Counter;
}

bool MyStringLib::IsVowel(char c)
{
    c = tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

short MyStringLib::CountVowelLetters(const string& Text)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (IsVowel(Letter)) Counter++;
    }
    return Counter;
}

short MyStringLib::CountWords(string Text)
{
    char Delim = ' ';
    string sWord = "";
    short Pos = 0;
    short Counter = 0;
    while ((Pos = Text.find(Delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        if (sWord != "") Counter++;
        Text.erase(0, Pos + 1);
    }
    if (Text != "") Counter++;
    return Counter;
}

void MyStringLib::PrintFirstLetterOfEachWord(const string& Text)
{
    bool IsFirstLetter = true;
    cout << "\nFirst Letter of Each Word:\n";
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
            cout << Text[i] << endl;
        IsFirstLetter = (Text[i] == ' ');
    }
}

void MyStringLib::PrintAllVowels(const string& Text)
{
    cout << "Vowels in string: ";
    for (const char &Letter : Text)
    {
        if (IsVowel(Letter)) cout << Letter << "   ";
    }
    cout << endl;
}

void MyStringLib::PrintEachWord(string Text)
{
    string delim = " ";
    short Pos = 0;
    string sWord = "";
    while ((Pos = Text.find(delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        if (sWord != "") cout << sWord << endl;
        Text.erase(0, Pos + 1);
    }
    if (Text != "") cout << Text << endl;
}

vector<string> MyStringLib::SplitString(string Text, string Delimiter)
{
    vector<string> vSpText;
    string sWord = "";
    short Pos = 0;
    while ((Pos = Text.find(Delimiter)) != string::npos)
    {
        sWord = Text.substr(0, Pos);
        vSpText.push_back(sWord);
        Text.erase(0, Pos + Delimiter.length());
    }
    if (Text != "") vSpText.push_back(Text);
    return vSpText;
}

string MyStringLib::TrimLeftSpaces(const string& Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ') return Text.substr(i);
    }
    return "";
}

string MyStringLib::TrimRightSpaces(const string& Text)
{
    for (short i = Text.length() - 1; i >= 0; i--)
    {
        if (Text[i] != ' ') return Text.substr(0, i + 1);
    }
    return "";
}

string MyStringLib::TrimSpaces(const string& Text)
{
    return TrimLeftSpaces(TrimRightSpaces(Text));
}

string MyStringLib::JoinStrings(const vector<string>& VectorOfStrings, string Delimiter)
{
    string sWord = "";
    for (const string &Word : VectorOfStrings)
        sWord += Word + Delimiter;
    return sWord.substr(0, (sWord.length() - Delimiter.length()));
}

string MyStringLib::JoinStrings(const string ArrayOfStrings[], short ArrayLength, string Delimiter)
{
    string sWord = "";
    for (short i = 0; i < ArrayLength; i++)
        sWord += ArrayOfStrings[i] + Delimiter;
    return sWord.substr(0, (sWord.length() - Delimiter.length()));
}

string MyStringLib::ReverseWordsOrder(const string& Text)
{
    string sWord = "";
    vector<string> vText = SplitString(Text, " ");
    vector<string>::iterator iter = vText.end();
    while (iter != vText.begin())
    {
        iter--;
        sWord += *iter + " ";
    }
    return sWord.substr(0, sWord.length() - 1);
}

string MyStringLib::ReplaceWord(string Text, const string& TargetWord, const string& ReplacementWord, bool MatchCase)
{
    if (TargetWord.empty()) return Text;
    size_t Pos = 0;

    if (MatchCase)
    {
        while ((Pos = Text.find(TargetWord, Pos)) != string::npos)
        {
            Text.replace(Pos, TargetWord.length(), ReplacementWord);
            Pos += ReplacementWord.length();
        }
    }
    else
    {
        string TextLower = LowerAllString(Text);
        string TargetLower = LowerAllString(TargetWord);

        while ((Pos = TextLower.find(TargetLower, Pos)) != string::npos)
        {
            Text.replace(Pos, TargetWord.length(), ReplacementWord);
            TextLower.replace(Pos, TargetLower.length(), LowerAllString(ReplacementWord));
            Pos += ReplacementWord.length();
        }
    }
    return Text;
}

string MyStringLib::RemovePunctuationMarks(const string& Text)
{
    string Result = "";
    for (const char &Character : Text)
    {
        if (!ispunct((unsigned char)Character)) Result += Character;
    }
    return Result;
}

// ============================================================================================================================================================
//                                                 4. INSTANCE METHODS (Operating on _Value)
// ============================================================================================================================================================
void MyStringLib::LowerAllString()                                                     { _Value = LowerAllString(_Value); }
void MyStringLib::CapitalizeAllString()                                                { _Value = CapitalizeAllString(_Value); }
void MyStringLib::InvertAllLettersCase()                                               { _Value = InvertAllLettersCase(_Value); }
void MyStringLib::CapitalizeFirstLetterOfEachWord()                                    { _Value = CapitalizeFirstLetterOfEachWord(_Value); }
void MyStringLib::LowerFirstLetterOfEachWord()                                         { _Value = LowerFirstLetterOfEachWord(_Value); }

short MyStringLib::CountLength() const                                                 { return CountLength(_Value); }
short MyStringLib::CountAllLetters() const                                             { return CountAllLetters(_Value); }
short MyStringLib::CountLowerCaseLetters() const                                       { return CountLowerCaseLetters(_Value); }
short MyStringLib::CountUpperCaseLetters() const                                       { return CountUpperCaseLetters(_Value); }
short MyStringLib::CountSpecificCharacter(char CharacterToCount, bool MatchCase) const { return CountSpecificCharacter(_Value, CharacterToCount, MatchCase); }
short MyStringLib::CountVowelLetters() const                                           { return CountVowelLetters(_Value); }
short MyStringLib::CountWords() const                                                  { return CountWords(_Value); }

void MyStringLib::PrintFirstLetterOfEachWord() const                                   { PrintFirstLetterOfEachWord(_Value); }
void MyStringLib::PrintAllVowels() const                                               { PrintAllVowels(_Value); }
void MyStringLib::PrintEachWord() const                                                { PrintEachWord(_Value); }

vector<string> MyStringLib::SplitString(string Delimiter) const                        { return SplitString(_Value, Delimiter); }
string MyStringLib::TrimLeftSpaces() const                                             { return TrimLeftSpaces(_Value); }
string MyStringLib::TrimRightSpaces() const                                            { return TrimRightSpaces(_Value); }
string MyStringLib::TrimSpaces() const                                                 { return TrimSpaces(_Value); }
string MyStringLib::ReverseWordsOrder() const                                          { return ReverseWordsOrder(_Value); }
string MyStringLib::RemovePunctuationMarks() const                                     { return RemovePunctuationMarks(_Value); }

string MyStringLib::ReplaceWord(const string& TargetWord, const string& ReplacementWord, bool MatchCase)
{
    return ReplaceWord(_Value, TargetWord, ReplacementWord, MatchCase);
}