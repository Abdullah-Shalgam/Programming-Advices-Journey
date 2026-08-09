#include <iostream>
#include "InputValidateLib.h"

using namespace std;

int ReadNumber()
{
    int Num;
    cout << "Please Enter a number: ";
    cin >> Num;
    return Num;
}

int main()
{
    int Num = InputValidateLib::ReadNumber("Please Enter a number: ");
    cout << Num << endl;
    Num = ReadNumber();
    cout << Num;
    return 0;
}