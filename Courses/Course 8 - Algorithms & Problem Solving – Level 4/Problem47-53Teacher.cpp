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
    Date.Day = InputLib::ReadIntNumberInRange(1, GetTotalDaysInMonth(Date.Year, Date.Month), "Please enter a Day: ");

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

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == GetTotalDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
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

short GetDiffInDaysBetWeenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short DaysDiff = GetNumberOfDaysFromTheBeginingOfTheYear(Date2) - GetNumberOfDaysFromTheBeginingOfTheYear(Date1);
    return (IncludeEndDay) ? ++DaysDiff : DaysDiff;
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

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

bool IsEndOfWeek(stDate Date)
{
    return GetDayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    short DayOfWeekOrder = GetDayOfWeekOrder(Date);
    return (DayOfWeekOrder == 5 || DayOfWeekOrder == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short GetDaysUntilEndOfWeek(stDate Date)
{
    return 6 - GetDayOfWeekOrder(Date);
}

short GetDaysUntilEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate = Date;
    EndOfMonthDate.Day = GetTotalDaysInMonth(Date.Year, Date.Month);
    return GetDiffInDaysBetWeenTwoDates(Date, EndOfMonthDate, true);
}

short GetDaysUntilEndOfYear(stDate Date)
{
    stDate EndOfMonthDate = {31, 12, Date.Year};
    return GetDiffInDaysBetWeenTwoDates(Date, EndOfMonthDate, true);
}

int main()
{
    stDate Date = GetSystemDate();

    cout << "Today is " << GetWeekDayName(GetDayOfWeekOrder(Date)) << " , ";
    PrintDate(Date);


    cout << "\n\nIs it End of Week?\n";
    if (IsEndOfWeek(Date))
        cout << "Yes it is Saturday, it is the end of the week.";
    else
        cout << "No, it is NOT the end of the week.";

    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(Date))
        cout << "Yes, it is the weekend.";
    else
        cout << "No today is " <<
        GetWeekDayName(GetDayOfWeekOrder(Date)) << ", Not a weekend.";

    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(Date))
        cout << "Yes, it is.";
    else
        cout << "No, it is NOT.";


    cout << "\n\nDays until end of week : " <<
    GetDaysUntilEndOfWeek(Date) << " Day(s).";
    cout << "\nDays until end of month : " <<
    GetDaysUntilEndOfMonth(Date) << " Day(s).";
    cout << "\nDays until end of year : " <<
    GetDaysUntilEndOfYear(Date) << " Day(s).";

    return 0;
}