#include <iostream>
#include "InputValidateLib.h"
#include <string>
#include <format>

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

string GetDate(short year, short month, short day)
{
    return format("{:02}/{:02}/{:04}", day, month, year);
}

short GetDayOrder(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetWeekDayName(short d)
{
    string arrWeekDaysName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    
    return arrWeekDaysName[d];
}

int main()
{
    short targetYear = InputValidateLib::ReadIntPositiveNumber("Please enter a year: ");
    short targetMonth = InputValidateLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");

    short targetDay = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(targetYear, targetMonth), "\nPlease enter a day: ");

    short DayOrder = GetDayOrder(targetYear, targetMonth, targetDay);

    cout << "\nDate      : " << GetDate(targetYear, targetMonth, targetDay);
    cout << "\nDay Order : " << DayOrder;
    cout << "\nDay Name  : " << GetWeekDayName(DayOrder);

    return 0;
}