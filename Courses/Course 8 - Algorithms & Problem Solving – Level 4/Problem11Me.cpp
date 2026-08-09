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

short GetNumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
{
    short TotalDays = 0;
    
    for (short i = 1; i < month; i++)
    {
        TotalDays += GetTotalDaysInMonth(year, i);
    }
    
    return TotalDays + day;
}

stDate GetDateFromDayOrderInYear(short DayOrderInYear, short year)
{
    short DaysInCurrentMonth = 0;

    for (short Month = 1; Month <= 12; Month++)
    {
        DaysInCurrentMonth = GetTotalDaysInMonth(year, Month);

        if (DayOrderInYear <= DaysInCurrentMonth)
        {
            return {DayOrderInYear, Month, year};
        }
        
        DayOrderInYear -= DaysInCurrentMonth;
    }

    return {0, 0, year}; //To cover all cases
}

int main()
{
    short targetYear = InputValidateLib::ReadIntPositiveNumber("Please enter a year: ");
    short targetMonth = InputValidateLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");
    short targetDay = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(targetYear, targetMonth), "\nPlease enter a day: ");
    
    short DayOrderInYear = GetNumberOfDaysFromTheBeginingOfTheYear(targetYear, targetMonth, targetDay);
    cout << "\nNumber of Days from the begining of the year is " << DayOrderInYear;

    stDate Date = GetDateFromDayOrderInYear(DayOrderInYear, targetYear);

    cout << "\n\nDate for[" << DayOrderInYear << "] is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}