#include <iostream>
#include <string>
#include "InputLib.h"

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
    stDate Date;
    Date.Year = year;
    Date.Month = 1;
    short RemainingDays = DayOrderInYear;
    short DaysInCurrentMonth = 0;

    while (true)
    {
        DaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        
        if(RemainingDays > DaysInCurrentMonth)
        {
            RemainingDays -= DaysInCurrentMonth;
            Date.Month++;
        }

        else
        {
            Date.Day = RemainingDays;
            return Date;
        }
    }
    
}

int main()
{
    short targetYear = InputLib::ReadIntPositiveNumber("Please enter a year: ");
    short targetMonth = InputLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");
    short targetDay = InputLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(targetYear, targetMonth), "\nPlease enter a day: ");
    
    short DayOrderInYear = GetNumberOfDaysFromTheBeginingOfTheYear(targetYear, targetMonth, targetDay);
    cout << "\nNumber of Days from the begining of the year is " << DayOrderInYear;

    stDate Date = GetDateFromDayOrderInYear(DayOrderInYear, targetYear);

    cout << "\n\nDate for[" << DayOrderInYear << "] is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}