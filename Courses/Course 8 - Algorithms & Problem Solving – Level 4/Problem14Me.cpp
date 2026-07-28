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

//bool IsDate1EqualsDate2(stDate Date1, stDate Date2)
//{
//    return (Date1.Year != Date2.Year) ? false : (Date1.Month != Date2.Month) ? false : (Date1.Day != Date2.Day) ? false : true;
//}

bool IsDate1EqualsDate2(stDate Date1, stDate Date2)
{
    return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << "\n";
    stDate Date2 = ReadFullDate();

    if (IsDate1EqualsDate2(Date1, Date2))
    {
        cout << "\nYes : Date1 is Equal To Date2.";
    }

    else
    {
        cout << "\nNo : Date1 is NOT Equal To Date2.";
    }

    return 0;
}