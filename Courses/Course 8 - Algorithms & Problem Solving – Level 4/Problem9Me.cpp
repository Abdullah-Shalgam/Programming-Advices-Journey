#include <iostream>
#include <string>
#include <iomanip>
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

short GetDayOrder(short year, short month, short day = 1)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetMonthName(short month)
{
    string arrMonthName[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return arrMonthName[month];
}

void PrintMonthCalendar(short year, short month)
{
    short dayOrder = GetDayOrder(year, month, 1);
    short totalDays = GetTotalDaysInMonth(year, month);

    cout << "\n  _______________" << GetMonthName(month) << "_______________\n\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int currentDayOfWeek = 0;
    for (currentDayOfWeek = 0; currentDayOfWeek < dayOrder; currentDayOfWeek++)
    {
        cout << "     ";
    }

    for (short day = 1; day <= totalDays; day++)
    {
        cout << setw(5) << day;

        if (++currentDayOfWeek == 7)
        {
            currentDayOfWeek = 0;
            cout << "\n";
        }
    }

    if (currentDayOfWeek != 0)
    {
        cout << "\n";
    }

    cout << "  _________________________________\n";
}

void PrintYearCalendar(short year)
{
    cout << "\n  _________________________________\n\n";
    cout << "          Calendar - " << year << "          ";
    cout << "\n  _________________________________\n";

    for (short i = 1; i <= 12; i++)
    {
        cout << "\n";
        PrintMonthCalendar(year, i);
    }
}

int main()
{
    short targetYear = InputValidateLib::ReadIntPositiveNumber("Please enter a year: ");

    PrintYearCalendar(targetYear);

    return 0;
}