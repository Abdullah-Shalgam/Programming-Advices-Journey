#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

string ConvertTextToLowerCase(string Text)
{
    for (char &Letter : Text) 
    {
        Letter = tolower(Letter);
    }
    return Text;
}

string ConvertTextToUpperCase(string Text)
{
    for (char &Letter : Text) 
    {
        Letter = toupper(Letter);
    }
    return Text;
}

int main()
{
    string S1 = InputValidateLib::ReadText("Please Enter Your Stirng?:\n");
    S1 = ConvertTextToUpperCase(S1);
    cout << "\nString after Upper:\n";
    cout << S1;
    S1 = ConvertTextToLowerCase(S1);
    cout << "\n\nString after Lower:\n";
    cout << S1;
    return 0;
}