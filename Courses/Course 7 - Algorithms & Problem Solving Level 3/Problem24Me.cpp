#include <iostream>
#include "InputValidateLib.h"
#include "MyStringLib.h"

using namespace std;

string UpperFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;
    
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
            Text[i] = toupper(Text[i]);
        IsFirstLetter = (Text[i] == ' ') ? true : false;
    }
    return Text;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    S1 = UpperFirstLetterOfEachWord(S1);
    cout << "\nString after conversion:\n\n";
    cout << S1 << endl;
    return 0;
}