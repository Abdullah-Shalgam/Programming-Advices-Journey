#include <iostream>
#include <string>
#include "InputLib.h"

using namespace std;

string ConvertNumToText(long long Num)
{
    if (Num == 0)
    {
        return "";
    }

    static const string NumbersFrom1To19[] = {
        "",        "One",       "Two",      "Three",    "Four", 
        "Five",    "Six",       "Seven",    "Eight",    "Nine", 
        "Ten",     "Eleven",    "Twelve",   "Thirteen", "Fourteen", 
        "Fifteen", "Sixteen",   "Seventeen","Eighteen", "Nineteen"
    };

    static const string Tens[] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

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

int main()
{
    long long Number = InputLib::ReadLongLongPositiveNumber("Please Enter a Number: ");
    cout << ConvertNumToText(Number) << endl;
    return 0;
}