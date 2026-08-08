#pragma once

#include <iostream>
#include <string>
#include <vector>
class MyStringLib
{
private:
    std::string _Value;

    enum class _enWhatToCount { CapitalLetters, SmallLetters, All };

    // --- Private Helper Method ---
    static short _CountLetters(const std::string& Str, _enWhatToCount WhatToCount = _enWhatToCount::All);

public:
    // --- Constructors ---
    MyStringLib();
    MyStringLib(const std::string& Value);

    // --- Setters & Getters ---
    void SetValue(const std::string& Value);
    std::string GetValue() const;

    // --- Static Utility Methods ---
    static std::string LowerAllString(std::string Text);
    static std::string CapitalizeAllString(std::string Text);
    static char InvertCharacterCase(char c);
    static std::string InvertAllLettersCase(std::string Text);
    static std::string CapitalizeFirstLetterOfEachWord(std::string Text);
    static std::string LowerFirstLetterOfEachWord(std::string Text);

    static short CountLength(const std::string& Text);
    static short CountAllLetters(const std::string& Text);
    static short CountLowerCaseLetters(const std::string& Text);
    static short CountUpperCaseLetters(const std::string& Text);
    static short CountSpecificCharacter(const std::string& Text, char CharacterToCount, bool MatchCase = true);
    static bool IsVowel(char c);
    static short CountVowelLetters(const std::string& Text);
    static short CountWords(std::string Text);

    static void PrintFirstLetterOfEachWord(const std::string& Text);
    static void PrintAllVowels(const std::string& Text);
    static void PrintEachWord(std::string Text);

    static std::vector<std::string> SplitString(std::string Text, std::string Delimiter);
    static std::string TrimLeftSpaces(const std::string& Text);
    static std::string TrimRightSpaces(const std::string& Text);
    static std::string TrimSpaces(const std::string& Text);
    static std::string JoinStrings(const std::vector<std::string>& VectorOfStrings, std::string Delimiter = " ");
    static std::string JoinStrings(const std::string ArrayOfStrings[], short ArrayLength, std::string Delimiter = " ");
    static std::string ReverseWordsOrder(const std::string& Text);
    static std::string ReplaceWord(std::string Text, const std::string& TargetWord, const std::string& ReplacementWord, bool MatchCase = true);
    static std::string RemovePunctuationMarks(const std::string& Text);

    // --- Instance Methods (Operating on _Value) ---
    void LowerAllString();
    void CapitalizeAllString();
    void InvertAllLettersCase();
    void CapitalizeFirstLetterOfEachWord();
    void LowerFirstLetterOfEachWord();

    short CountLength() const;
    short CountAllLetters() const;
    short CountLowerCaseLetters() const;
    short CountUpperCaseLetters() const;
    short CountSpecificCharacter(char CharacterToCount, bool MatchCase = true) const;
    short CountVowelLetters() const;
    short CountWords() const;

    void PrintFirstLetterOfEachWord() const;
    void PrintAllVowels() const;
    void PrintEachWord() const;

    std::vector<std::string> SplitString(std::string Delimiter) const;
    std::string TrimLeftSpaces() const;
    std::string TrimRightSpaces() const;
    std::string TrimSpaces() const;
    std::string ReverseWordsOrder() const;
    std::string RemovePunctuationMarks() const;
    std::string ReplaceWord(const std::string& TargetWord, const std::string& ReplacementWord, bool MatchCase = true);
};