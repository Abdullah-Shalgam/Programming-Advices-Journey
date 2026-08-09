#include <iostream>
#include "InputValidateLib.h"

using namespace std;

bool IsLeapYear(short Year)
{
    if (Year % 400 == 0) {
    return true;
    }

    else if (Year % 100 == 0) {
    return false;
    }

    else if (Year % 4 == 0) {
    return true;
    }
    
    else {
    return false;
    }
}

int main()
{
    short Year = InputValidateLib::ReadIntPositiveNumber("Enter The Year : ");

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