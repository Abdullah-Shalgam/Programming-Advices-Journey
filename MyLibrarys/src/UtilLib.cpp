#include "UtilLib.h"

using namespace std;

void UtilLib::Srand()
{
    srand((unsigned)time(NULL));
}

string UtilLib::GetSystemDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d | %H:%M:%S", ltm);
    return string(buffer);
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

void UtilLib::PrintHeaderLine(char symbol, short width)
{
    cout << string(width, symbol) << "\n";
}

void UtilLib::PrintCentered(string text, short width)
{
    if (text.length() >= width)
    {
        cout << text << "\n";
        return;
    }
    short padding = (width - text.length()) / 2;
    cout << string(padding, ' ') << text << "\n";
}

string UtilLib::Truncate(const string &Text, short MaxLen, const string &Ellipsis)
{
    if (MaxLen <= 0)
        return "";

    if ((short)Text.length() > MaxLen)
    {
        if (MaxLen <= (short)Ellipsis.length())
            return Text.substr(0, MaxLen);

        return Text.substr(0, MaxLen - (short)Ellipsis.length()) + Ellipsis;
    }
    return Text;
}

void UtilLib::ResetTheScreen()
{
    cout << UtilLib::GetColor(UtilLib::enColor::Reset) << flush;
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

string UtilLib::DecryptText(string Text, short EncryptionKey)
{
    for (size_t i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

string UtilLib::XOREncryptDecrypt(string Text, string Key)
{
    for (size_t i = 0; i < Text.length(); i++)
    {
        Text[i] = Text[i] ^ Key[i % Key.length()];
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
        if (SpecialCharacterRange == 1)
            return char(RandomNumber(33, 47));
        if (SpecialCharacterRange == 2)
            return char(RandomNumber(58, 64));
        if (SpecialCharacterRange == 3)
            return char(RandomNumber(91, 96));
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
        if (i != 4)
            Key += '-';
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

string UtilLib::ConvertNumToText(long long Num)
{
    if (Num == 0)
    {
        return "";
    }

    static const string NumbersFrom1To19[] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    static const string Tens[] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (Num >= 1 && Num <= 19)
    {
        return NumbersFrom1To19[Num];
    }

    if (Num >= 20 && Num <= 99)
    {
        string remainder = ConvertNumToText(Num % 10);
        return Tens[Num / 10] + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 100 && Num <= 999)
    {
        string remainder = ConvertNumToText(Num % 100);
        return ConvertNumToText(Num / 100) + " Hundred" + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 1000 && Num <= 999999)
    {
        string remainder = ConvertNumToText(Num % 1000);
        return ConvertNumToText(Num / 1000) + " Thousand" + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 1000000 && Num <= 999999999)
    {
        string remainder = ConvertNumToText(Num % 1000000);
        return ConvertNumToText(Num / 1000000) + " Million" + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 1000000000 && Num <= 999999999999LL)
    {
        string remainder = ConvertNumToText(Num % 1000000000);
        return ConvertNumToText(Num / 1000000000) + " Billion" + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 1000000000000LL && Num <= 999999999999999LL)
    {
        string remainder = ConvertNumToText(Num % 1000000000000LL);
        return ConvertNumToText(Num / 1000000000000LL) + " Trillion" + (remainder.empty() ? "" : " " + remainder);
    }

    if (Num >= 1000000000000000LL && Num <= 999999999999999999LL)
    {
        string remainder = ConvertNumToText(Num % 1000000000000000LL);
        return ConvertNumToText(Num / 1000000000000000LL) + " Quadrillion" + (remainder.empty() ? "" : " " + remainder);
    }

    return "";
}

#include <iostream>

long long UtilLib::GetFractionalPartAsInt(double num, int precision)
{
    if (num < 0)
    {
        num = -num;
    }

    double fractional_part = num - (long long)num;

    for (int i = 0; i < precision; ++i)
    {
        fractional_part *= 10;
    }

    long long result = (long long)(fractional_part + 0.5);

    return result;
}

string UtilLib::ConvertNumToTextWithDecimals(double Number, string MainCurrency, string SubCurrency)
{
    long long IntegerPart = (long long)Number;
    int FractionPart = GetFractionalPartAsInt(Number, 2);

    string Text = UtilLib::ConvertNumToText(IntegerPart) + " " + MainCurrency;

    if (FractionPart > 0)
    {
        Text += " and " + UtilLib::ConvertNumToText(FractionPart) + " " + SubCurrency;
    }

    return Text;
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

// Color Functions

string UtilLib::GetColor(enColor Color)
{
    return "\033[" + to_string(static_cast<int>(Color)) + "m";
}

string UtilLib::ColorText(const string &Text, enColor Color)
{
    return GetColor(Color) + Text + GetColor(enColor::Reset);
}

void UtilLib::PrintColor(const string &Text, enColor Color, bool NewLine)
{
    cout << ColorText(Text, Color);
    if (NewLine)
        cout << endl;
}

void UtilLib::TypeWriterText(string text, int speedInMs)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speedInMs));
    }
}

void UtilLib::ShowSpinner(string Message, int cycles)
{
    char spinner[] = {'|', '/', '-', '\\'};
    cout << "\n\t" << Message << " ";

    for (int i = 0; i < cycles * 4; i++)
    {
        cout << spinner[i % 4] << "\b" << flush;
        this_thread::sleep_for(chrono::milliseconds(120));
    }
    cout << "Done!\n";
}

void UtilLib::ShowProgressBar(string Message)
{
    cout << "\n\n\t" << Message << "\n\t[";
    for (int i = 0; i < 30; i++)
    {
        cout << "=" << flush;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
    cout << "] 100% Completed!\n\n";
    this_thread::sleep_for(chrono::milliseconds(200));
}

void UtilLib::FlashWarningText(string Message)
{
    cout << UtilLib::GetColor(UtilLib::enColor::BgRed)
         << UtilLib::GetColor(UtilLib::enColor::White)
         << " " << Message << " "
         << UtilLib::GetColor(UtilLib::enColor::Reset) << flush;

    this_thread::sleep_for(chrono::milliseconds(300));
}