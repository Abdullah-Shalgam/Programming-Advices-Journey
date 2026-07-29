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
    Date.Month = InputLib::ReadIntPositiveNumber("Please enter a Month: ");
    Date.Day = InputLib::ReadIntPositiveNumber("Please enter a Day: ");

    return Date;
}

bool IsValideDate(stDate Date)
{
    return (Date.Month >= 1 && Date.Month <= 12) && 
           (Date.Day >= 1 && Date.Day <= GetTotalDaysInMonth(Date.Year, Date.Month));
}

int main()
{
    stDate Date = ReadFullDate();
    
    if (IsValideDate(Date))
    {
        cout << "Yes, Date is a valide Date.";
    }
    else
    {
        cout << "No, Date is NOT a valide Date.";
    }
    return 0;
}