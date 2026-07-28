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

    Date.Year = InputLib::ReadIntPositiveNumber("Please enter a Year: ");
    Date.Month = InputLib::ReadIntNumberInRange(1, 12, "Please enter a Month: ");
    Date.Day = InputLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : 
           (Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : 
                                        (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) 
                                      : false;
}

bool IsDate1EqualsDate2(stDate Date1, stDate Date2)
{
    return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
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

short GetDiffInDaysBetWeenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    bool IsSwapped = false;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapTwoDates(Date1, Date2);
        IsSwapped = true;
    }

    short DaysDiff = 0;

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

    if (IncludeEndDay) DaysDiff++;

    return (IsSwapped) ? -DaysDiff : DaysDiff;
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << "\n";
    stDate Date2 = ReadFullDate();

    cout << "\nDiffrence is: " <<
    GetDiffInDaysBetWeenTwoDates(Date1, Date2) << " Day(s).";
    cout << "\nDiffrence (Including End Day) is: " <<
    GetDiffInDaysBetWeenTwoDates(Date1, Date2, true) << " Day(s).";

    return 0;
}