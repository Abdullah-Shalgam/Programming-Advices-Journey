#include <iostream>
#include "InputLib.h"

using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

int main()
{
    short Year = InputLib::ReadIntPositiveNumber("Enter The Year : ");
    
    if (IsLeapYear(Year))
    {
        cout << "Yes: Year " << Year << " is a leap year.";
    }

    else
    {
        cout << "NO: Year " << Year << " is Not a leap year.";
    }
    
    return 0;
}