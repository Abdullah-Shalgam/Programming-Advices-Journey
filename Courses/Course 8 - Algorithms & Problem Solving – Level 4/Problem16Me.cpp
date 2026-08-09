#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

bool IsLeapYear(short year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short GetTotalDaysInMonth(short year, short month)
{
    short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return (month == 2 && IsLeapYear(year)) ? 29 : DaysInMonths[month];
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Year = InputValidateLib::ReadIntPositiveNumber("Please enter a Year: ");
    Date.Month = InputValidateLib::ReadIntNumberInRange(1, 12, "Please enter a Month: ");
    Date.Day = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

    return Date;
}

void PrintDate(stDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == GetTotalDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        Date.Day = 1;

        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "\nDate after adding one day is : ";
    PrintDate(Date);

    return 0;
}