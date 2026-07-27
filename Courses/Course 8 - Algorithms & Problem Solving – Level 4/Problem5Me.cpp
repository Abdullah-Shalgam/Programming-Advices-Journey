#include <iostream>
#include "InputLib.h"

using namespace std;

bool IsLeapYear(short year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short GetTotalDaysInMonth(short year, short month)
{
    short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return DaysInMonths[month] + ((month == 2 && IsLeapYear(year)) ? 1 : 0);
}

int GetTotalHoursInMonth(short year, short month)
{
    return GetTotalDaysInMonth(year, month) * 24;
}

long GetTotalMinutesInMonth(short year, short month)
{
    return GetTotalHoursInMonth(year, month) * 60;
}

long long GetTotalSecondsInMonth(short year, short month)
{
    return GetTotalMinutesInMonth(year, month) * 60;
}

int main()
{
    short targetYear = InputLib::ReadIntPositiveNumber("Please enter a year to check: ");
    short targetMonth = InputLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month to check: ");

    cout << "\nNumber Of Days    in Month [" << targetMonth << "] is " <<
    GetTotalDaysInMonth(targetYear, targetMonth);
    cout << "\nNumber Of Hours   in Month [" << targetMonth << "] is " <<
    GetTotalHoursInMonth(targetYear, targetMonth);
    cout << "\nNumber Of Minutes in Month [" << targetMonth << "] is " <<
    GetTotalMinutesInMonth(targetYear, targetMonth);
    cout << "\nNumber Of Seconds in Month [" << targetMonth << "] is " <<
    GetTotalSecondsInMonth(targetYear, targetMonth) << endl;

    return 0;
}