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

    Date.Year = InputLib::ReadIntPositiveNumber("Please enter a Year: ");
    Date.Month = InputLib::ReadIntNumberInRange(1, 12, "Please enter a Month: ");
    Date.Day = InputLib::ReadIntNumberInRange
    (1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

    return Date;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year && (GetNumberOfDaysFromTheBeginingOfTheYear(Date1) < GetNumberOfDaysFromTheBeginingOfTheYear(Date2))) ? true : false;
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << "\n";
    stDate Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1, Date2))
    {
        cout << "\nYes : Date1 is Less than Date2.";
    }

    else
    {
        cout << "\nNo : Date1 is NOT Less than Date2.";
    }

    return 0;
}