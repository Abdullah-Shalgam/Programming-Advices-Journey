#include <iostream>
#include "InputLib.h"

using namespace std;

void PrintFirstLetterOfEachWord(string Text)
{
    cout << "\nFirst Letter of Each Word From Your string is : \n\n";
    cout << Text[0] << endl;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] == ' ')
            cout << Text[i+1] << endl;
    }
}

int main()
{
    PrintFirstLetterOfEachWord(InputLib::ReadText("Please enter the Text: \n"));
    return 0;
}