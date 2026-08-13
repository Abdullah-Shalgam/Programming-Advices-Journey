#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>
#include "DateLib.h"

using namespace std;

class UtilLib
{
private:
    static const short _ConsoleWidth = 80;

public:
    enum class enCharType
    {
        SmallCharacter = 1,
        CapitalCharacter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };
    enum class enColor
    {
        Reset = 0,
        Bold = 1,
        Underline = 4,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        BrightRed = 91,
        BrightGreen = 92,
        BrightYellow = 93,
        BrightBlue = 94,
        BrightMagenta = 95,
        BrightCyan = 96,
        BgRed = 41,
        BgGreen = 42,
        BgYellow = 43,
        BgBlue = 44,
        BgCyan = 46
    };

    static void Srand();
    static string Tabs(int Count);
    static void PrintHeaderLine(char symbol = '=', short width = _ConsoleWidth);
    static void PrintCentered(string text, short width = _ConsoleWidth);
    static string GetColor(enColor Color);
    static string ColorText(const string &Text, enColor Color);
    static void PrintColor(const string &Text, enColor Color, bool NewLine = true);
    static void TypeWriterText(string text = "Processing...", int speedInMs = 30);
    static void ShowSpinner(string Message = "Processing, please wait...", int cycles = 3);
    static void ShowProgressBar(string Message = "Loading data, please wait...");
    static void FlashWarningText(string Message = "WARNING");
    static string Truncate(const string &Text, short MaxLen, const string &Ellipsis = "...");
    static void ResetTheScreen();
    static string EncryptText(string Text, short EncryptionKey);
    static string DecryptText(string Text, short EncryptionKey);
    static int RandomNumber(int From, int To);
    static char GetRandomCharacter(enCharType CharType);
    static string GenerateWord(enCharType CharType, short Length);
    static string GenerateKey(enCharType CharType = enCharType::CapitalCharacter);
    static void GenerateKeys(short NumberOfKeys, enCharType CharType = enCharType::CapitalCharacter);
    static string ConvertNumToText(long long Num);
    static long long GetFractionalPartAsInt(double num, int precision);
    static string ConvertNumToTextWithDecimals(double Number);

    static void FillArrayWithRandomNumbers(int Array[], int ArrayLength, int From, int To);
    static void FillArrayWithRandomWords(string Array[], int ArrayLength, enCharType CharType, short Length);
    static void FillArrayWithRandomKeys(string Array[], int ArrayLength, enCharType CharType);

    // Template functions MUST be defined in the header file
    template <typename T>
    static void Swap(T &A, T &B)
    {
        T Temp = A;
        A = B;
        B = Temp;
    }

    template <typename T>
    static void ShuffleArray(T Array[], int ArrayLength)
    {
        for (int i = ArrayLength - 1; i > 0; i--)
        {
            Swap(Array[i], Array[RandomNumber(0, i)]);
        }
    }
};