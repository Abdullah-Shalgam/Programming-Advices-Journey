#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

enum enCompareDates { Before = -1, Equal = 0, After = 1 };

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

    Date.Year = InputValidateLib::ReadIntPositiveNumber("Please enter a Year: ");
    Date.Month = InputValidateLib::ReadIntNumberInRange(1, 12, "Please enter a Month: ");
    Date.Day = InputValidateLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "Enter Start Date:\n\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == GetTotalDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : 
           (Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : 
                                        (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) 
                                      : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

short GetNumberOfDaysFromTheBeginingOfTheYear(stDate Date)
{
    short TotalDays = 0;
    
    for (short i = 1; i < Date.Month; i++)
    {
        TotalDays += GetTotalDaysInMonth(Date.Year, i);
    }
    
    return TotalDays + Date.Day;
}

void SwapTwoDates(stDate &Date1, stDate &Date2)
{
    stDate Temp = Date1;
    Date1 = Date2;
    Date2 = Temp;
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

enCompareDates CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2)) return enCompareDates::Before;
    if (IsDate1EqualDate2(Date1, Date2)) return enCompareDates::Equal;
    return enCompareDates::After;
}

int GetDiffInDaysBetWeenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int DaysDiff = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2))
    {
        SwapTwoDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    if (Date1.Year < Date2.Year)
    {
        DaysDiff += GetTotalDaysInYear(Date1.Year) - GetNumberOfDaysFromTheBeginingOfTheYear(Date1);
        Date1.Year++;

        while (Date1.Year < Date2.Year)
        {
            DaysDiff += GetTotalDaysInYear(Date1.Year);
            Date1.Year++;
        }

        DaysDiff += GetNumberOfDaysFromTheBeginingOfTheYear(Date2);
    }
    else
    {
        DaysDiff = GetNumberOfDaysFromTheBeginingOfTheYear(Date2) - GetNumberOfDaysFromTheBeginingOfTheYear(Date1);
    }

    return IncludeEndDay ? (DaysDiff + 1) * SwapFlagValue : DaysDiff * SwapFlagValue;
}

bool IsOverlapPeriod(stPeriod Period1, stPeriod Period2)
{
    return !((CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDates::Before) ||
             (CompareDates(Period1.EndDate, Period2.StartDate) == enCompareDates::Before));
}

short GetCountOverlapDays(stPeriod Period1, stPeriod Period2, bool IncludeEndDate = false)
{
    if (IsOverlapPeriod(Period1, Period2))
    {
        stDate OverlapStart = IsDate1BeforeDate2(Period2.StartDate, Period1.StartDate) ? Period1.StartDate : Period2.StartDate;
        stDate OverlapEnd   = IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate)     ? Period1.EndDate   : Period2.EndDate;

        return GetDiffInDaysBetWeenTwoDates(OverlapStart, OverlapEnd, IncludeEndDate);
    }

    return 0;
}

int main()
{
    cout << "Enter Period1:\n";
    stPeriod Period1 = ReadPeriod();
    
    cout << "\n\nEnter Period2:\n";
    stPeriod Period2 = ReadPeriod();

    cout << "\n\nOverlaps Days Count is: " << GetCountOverlapDays(Period1, Period2);

    return 0;
}