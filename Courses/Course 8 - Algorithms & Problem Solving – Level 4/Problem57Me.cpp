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

enCompareDates CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2)) return enCompareDates::Before;
    if (IsDate1EqualDate2(Date1, Date2)) return enCompareDates::Equal;
    return enCompareDates::After;
}

int main()
{
    cout << "Enter Date1:\n";
    stDate Date1 = ReadFullDate();
    cout << "\n";
    cout << "Enter Date2:\n";
    stDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2);

    return 0;
}