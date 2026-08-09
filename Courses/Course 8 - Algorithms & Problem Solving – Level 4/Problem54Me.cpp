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

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == GetTotalDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Year = InputValidateLib::ReadIntPositiveNumber("Please enter a Year: ");
    Date.Month = InputValidateLib::ReadIntNumberInRange(1, 12, "Please enter a Month: ");
    Date.Day = InputValidateLib::ReadIntNumberInRange(1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

    return Date;
}

string GetWeekDayName(short DayOfWeekOrder)
{
    string arrWeekDaysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    
    return arrWeekDaysName[DayOfWeekOrder];
}

void PrintDate(stDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
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

short GetDayOfWeekOrder(short year, short month, short day = 1)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short GetDayOfWeekOrder(stDate Date)
{
    return GetDayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : 
           (Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : 
                                        (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) 
                                      : false;
}

bool IsWeekEnd(stDate Date)
{
    short DayOfWeekOrder = GetDayOfWeekOrder(Date);
    return (DayOfWeekOrder == 5 || DayOfWeekOrder == 6);
}

short GetVacationDays(stDate VacationStart, stDate VacationEnd, bool IncludeEndDay = false)
{
    short Counter = 0;

    while(IsDate1BeforeDate2(VacationStart, VacationEnd))
    {
        if (!IsWeekEnd(VacationStart))
        {
            Counter++;
        }

        VacationStart = IncreaseDateByOneDay(VacationStart);
    }

    if (IncludeEndDay && !IsWeekEnd(VacationEnd))
    {
        Counter++;
    }

    return Counter;
}

int main()
{
    cout << "Vacation Starts:\n";
    stDate VacationStart = ReadFullDate();
    cout << "\n";
    cout << "Vacation Ends:\n";
    stDate VacationEnd = ReadFullDate();

    cout << "\nVacation From: " << GetWeekDayName(GetDayOfWeekOrder(VacationStart))
    << " , "; PrintDate(VacationStart);

    cout << "\nVacation To: " << GetWeekDayName(GetDayOfWeekOrder(VacationEnd))
    << " , "; PrintDate(VacationEnd);

    cout << "\n\n\nActual Vacation Days is: " << GetVacationDays(VacationStart, VacationEnd);
    
    return 0;
}