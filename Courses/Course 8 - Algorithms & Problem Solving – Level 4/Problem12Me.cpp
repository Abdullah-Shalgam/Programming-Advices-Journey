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

short GetTotalDaysInYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}

short GetTotalDaysInMonth(short year, short month)
{
    short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return (month == 2 && IsLeapYear(year)) ? 29 : DaysInMonths[month];
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Year = InputValidateLib::ReadIntPositiveNumber("Please enter a year: ");
    Date.Month = InputValidateLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");
    Date.Day = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(Date.Year, Date.Month), "\nPlease enter a day: ");

    return Date;
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

stDate GetDateAfterAddingDays(short DaysAdded, stDate Date)
{
    short DaysInCurrentYear = 0;
    short DayOrderInYear = GetNumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    short TotalDays = DayOrderInYear + DaysAdded;
    
    while (TotalDays > (DaysInCurrentYear = GetTotalDaysInYear(Date.Year)))
    {
        TotalDays -= DaysInCurrentYear;
        Date.Year++;
    }

    return GetDateFromDayOrderInYear(TotalDays, Date.Year);
}

int main()
{
    stDate Date = ReadFullDate();
    short DaysToAdd = InputValidateLib::ReadIntPositiveNumber("\nHow many days to add: ");
    
    Date = GetDateAfterAddingDays(DaysToAdd, Date);

    cout << "\n\nDate after adding [" << DaysToAdd << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}