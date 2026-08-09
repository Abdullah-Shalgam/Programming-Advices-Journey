#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "DateLib.h"

using namespace std;

class UtilLib
{
public:
    enum class enCharType { SmallCharacter = 1, CapitalCharacter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5 };

    static void Srand();
    static string Tabs(int Count);
    static void ResetTheScreen();
    static string EncryptText(string Text, short EncryptionKey);
    static string DecryptionText(string Text, short EncryptionKey);
    static int RandomNumber(int From, int To);
    static char GetRandomCharacter(enCharType CharType);
    static string GenerateWord(enCharType CharType, short Length);
    static string GenerateKey(enCharType CharType = enCharType::CapitalCharacter);
    static void GenerateKeys(short NumberOfKeys, enCharType CharType = enCharType::CapitalCharacter);
    
    static void FillArrayWithRandomNumbers(int Array[], int ArrayLength, int From, int To);
    static void FillArrayWithRandomWords(string Array[], int ArrayLength, enCharType CharType, short Length);
    static void FillArrayWithRandomKeys(string Array[], int ArrayLength, enCharType CharType);

    // Template functions MUST be defined in the header file
    template <typename T>
    static void Swap(T& A, T& B)
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