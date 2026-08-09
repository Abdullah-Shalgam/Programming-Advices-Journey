#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

bool IsLeapYear(short year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short GetTotalDaysInMonth(short year, short month)
{
    short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return (month == 2 && IsLeapYear(year)) ? 29 : DaysInMonths[month];
}

short GetNumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
{
    short TotalDays = 0;
    
    for (short i = 1; i < month; i++)
    {
        TotalDays += GetTotalDaysInMonth(year, i);
    }
    
    return TotalDays + day;
}

int main()
{
    short targetYear = InputValidateLib::ReadIntPositiveNumber("Please enter a year: ");
    short targetMonth = InputValidateLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");
    
    short targetDay = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(targetYear, targetMonth), "\nPlease enter a day: ");
    

    cout << "\nNumber of Days from the begining of the year is " <<
    GetNumberOfDaysFromTheBeginingOfTheYear(targetYear, targetMonth, targetDay);

    return 0;
}