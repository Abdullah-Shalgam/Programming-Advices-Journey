#include <iostream>
#include <string>
#include <cctype>
#include "InputLib.h"

using namespace std;

enum enWhatToCount {CapitalLetters = 1, SmallLetters = 2, All = 3};

short CountLetters(string Str, enWhatToCount WhatToCount = enWhatToCount::All)
{
    
    if (WhatToCount == enWhatToCount::All)
        return Str.length();
    
    short Counter = 0;
    for (const char Letter : Str)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Letter))
            Counter++;
        else if (WhatToCount == enWhatToCount::SmallLetters && islower(Letter))
            Counter++;
    }
    return Counter;
}

short CountUpperCaseLettersInText(string Text)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (isupper(Letter))
            Counter++;
    }
    return Counter;
}

short CountLowerCaseLettersInText(string Text)
{
    short Counter = 0;
    for (const char &Letter : Text)
    {
        if (islower(Letter))
            Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = InputLib::ReadText("Please Enter Your stirng?:\n");
    cout << "\nMethod 1:\n\n";
    cout << "\nString Length = " << S1.length();
    cout << "\nCapital Letters Count= " << CountUpperCaseLettersInText(S1);
    cout << "\nSmall Letters Count= " << CountLowerCaseLettersInText(S1);
    cout << "\n\nMethod 2:\n\n";
    cout << "\nString Length = " << CountLetters(S1);
    cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count = " << CountLetters(S1, enWhatToCount::SmallLetters);
    return 0;
}
