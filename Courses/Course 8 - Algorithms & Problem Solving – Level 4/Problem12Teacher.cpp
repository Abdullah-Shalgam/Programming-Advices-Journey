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

stDate ReadFullDate()
{
    stDate Date;

    Date.Year = InputLib::ReadIntPositiveNumber("Please enter a year: ");
    Date.Month = InputLib::ReadIntNumberInRange(1, 12, "\nPlease enter a month: ");
    Date.Day = InputLib::ReadIntNumberInRange
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

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days + GetNumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    short DaysInCurrentMonth = 0;

    Date.Month = 1;

    while (true)
    {
        DaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        
        if (RemainingDays > DaysInCurrentMonth)
        {
            RemainingDays -= DaysInCurrentMonth;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
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
    stDate Date = ReadFullDate();
    short DaysToAdd = InputLib::ReadIntPositiveNumber("\nHow many days to add: ");
    
    Date = DateAddDays(DaysToAdd, Date);

    cout << "\n\nDate after adding [" << DaysToAdd << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}