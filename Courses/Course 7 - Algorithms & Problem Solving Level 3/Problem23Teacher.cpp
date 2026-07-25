#include <iostream>
#include "InputLib.h"

using namespace std;

void PrintFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;
    cout << "\nFirst Letter of Each Word From Your string is : \n\n";
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
            cout << Text[i] << endl;
        IsFirstLetter = (Text[i] == ' ') ? true : false;
    }
}

int main()
{
    PrintFirstLetterOfEachWord(InputLib::ReadText("Please enter the Text: \n"));
    return 0;
}