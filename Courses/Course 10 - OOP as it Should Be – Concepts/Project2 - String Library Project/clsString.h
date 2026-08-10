#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyStringLib
{
private:
    string _Value;

    enum class _enWhatToCount { CapitalLetters, SmallLetters, All };

    // --- Private Helper Methods ---
    static short _CountLetters(const string& Str, _enWhatToCount WhatToCount = _enWhatToCount::All)
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

public:

    // ===================================================
    // 1. CONSTRUCTORS
    // ===================================================
    MyStringLib() 
    { 
        _Value = ""; 
    }

    MyStringLib(const string& Value) 
    { 
        _Value = Value; 
    }

    // ===================================================
    // 2. SETTERS & GETTERS
    // ===================================================
    void SetValue(const string& Value) { _Value = Value; }
    string GetValue() const            { return _Value; }

    // ===================================================
    // 3. STATIC UTILITY METHODS (General Functions)
    // ===================================================

    // --- Case Manipulation ---
    static string LowerAllString(string Text)
    {
        for (char &Letter : Text) 
            Letter = tolower((unsigned char)Letter);
        return Text;
    }

    static string CapitalizeAllString(string Text)
    {
        for (char &Letter : Text) 
            Letter = toupper((unsigned char)Letter);
        return Text;
    }

    static char InvertCharacterCase(char c)
    {
        return (islower((unsigned char)c)) ? toupper((unsigned char)c) : tolower((unsigned char)c);
    }

    static string InvertAllLettersCase(string Text)
    {
        for (char &Letter : Text)
            Letter = InvertCharacterCase(Letter);
        return Text;
    }

    static string CapitalizeFirstLetterOfEachWord(string Text)
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

    static string LowerFirstLetterOfEachWord(string Text)
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

    // --- Counting & Analytics ---
    static short CountLength(const string& Text)
    {
        return Text.length();
    }

    static short CountAllLetters(const string& Text)
    {
        return _CountLetters(Text, _enWhatToCount::All);
    }

    static short CountLowerCaseLetters(const string& Text)
    {
        return _CountLetters(Text, _enWhatToCount::SmallLetters);
    }

    static short CountUpperCaseLetters(const string& Text)
    {
        return _CountLetters(Text, _enWhatToCount::CapitalLetters);
    }

    static short CountSpecificCharacter(const string& Text, char CharacterToCount, bool MatchCase = true)
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

    static bool IsVowel(char c)
    {
        c = tolower((unsigned char)c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    static short CountVowelLetters(const string& Text)
    {
        short Counter = 0;
        for (const char &Letter : Text)
        {
            if (IsVowel(Letter)) Counter++;
        }
        return Counter;
    }

    static short CountWords(string Text)
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

    // --- Printing Helpers ---
    static void PrintFirstLetterOfEachWord(const string& Text)
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

    static void PrintAllVowels(const string& Text)
    {
        cout << "Vowels in string: ";
        for (const char &Letter : Text)
        {
            if (IsVowel(Letter)) cout << Letter << "   ";
        }
        cout << endl;
    }

    static void PrintEachWord(string Text)
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

    // --- Transformations (Splitting, Joining, Trimming, Replace) ---
    static vector<string> SplitString(string Text, string Delimiter)
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

    static string TrimLeftSpaces(const string& Text)
    {
        for (short i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ') return Text.substr(i);
        }
        return "";
    }

    static string TrimRightSpaces(const string& Text)
    {
        for (short i = Text.length() - 1; i >= 0; i--)
        {
            if (Text[i] != ' ') return Text.substr(0, i + 1);
        }
        return "";
    }

    static string TrimSpaces(const string& Text)
    {
        return TrimLeftSpaces(TrimRightSpaces(Text));
    }

    static string JoinStrings(const vector<string>& VectorOfStrings, string Delimiter = " ")
    {
        string sWord = "";
        for (const string &Word : VectorOfStrings)
            sWord += Word + Delimiter;
        return sWord.substr(0, (sWord.length() - Delimiter.length()));
    }

    static string JoinStrings(const string ArrayOfStrings[], short ArrayLength, string Delimiter = " ")
    {
        string sWord = "";
        for (short i = 0; i < ArrayLength; i++)
            sWord += ArrayOfStrings[i] + Delimiter;
        return sWord.substr(0, (sWord.length() - Delimiter.length()));
    }

    static string ReverseWordsOrder(const string& Text)
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

    static string ReplaceWord(string Text, const string& TargetWord, const string& ReplacementWord, bool MatchCase = true)
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

    static string RemovePunctuationMarks(const string& Text)
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
    void LowerAllString()                                                            { _Value = LowerAllString(_Value); }
    void CapitalizeAllString()                                                       { _Value = CapitalizeAllString(_Value); }
    void InvertAllLettersCase()                                                      { _Value = InvertAllLettersCase(_Value); }
    void CapitalizeFirstLetterOfEachWord()                                           { _Value = CapitalizeFirstLetterOfEachWord(_Value); }
    void LowerFirstLetterOfEachWord()                                                { _Value = LowerFirstLetterOfEachWord(_Value); }

    short CountLength() const                                                        { return CountLength(_Value); }
    short CountAllLetters() const                                                    { return CountAllLetters(_Value); }
    short CountLowerCaseLetters() const                                              { return CountLowerCaseLetters(_Value); }
    short CountUpperCaseLetters() const                                              { return CountUpperCaseLetters(_Value); }
    short CountSpecificCharacter(char CharacterToCount, bool MatchCase = true) const { return CountSpecificCharacter(_Value, CharacterToCount, MatchCase); }
    short CountVowelLetters() const                                                  { return CountVowelLetters(_Value); }
    short CountWords() const                                                         { return CountWords(_Value); }

    void PrintFirstLetterOfEachWord() const                                          { PrintFirstLetterOfEachWord(_Value); }
    void PrintAllVowels() const                                                      { PrintAllVowels(_Value); }
    void PrintEachWord() const                                                       { PrintEachWord(_Value); }

    vector<string> SplitString(string Delimiter) const                               { return SplitString(_Value, Delimiter); }
    string TrimLeftSpaces() const                                                    { return TrimLeftSpaces(_Value); }
    string TrimRightSpaces() const                                                   { return TrimRightSpaces(_Value); }
    string TrimSpaces() const                                                        { return TrimSpaces(_Value); }
    string ReverseWordsOrder() const                                                 { return ReverseWordsOrder(_Value); }
    string RemovePunctuationMarks() const                                            { return RemovePunctuationMarks(_Value); }

    string ReplaceWord(const string& TargetWord, const string& ReplacementWord, bool MatchCase = true)
    {
        return ReplaceWord(_Value, TargetWord, ReplacementWord, MatchCase);
    }
};