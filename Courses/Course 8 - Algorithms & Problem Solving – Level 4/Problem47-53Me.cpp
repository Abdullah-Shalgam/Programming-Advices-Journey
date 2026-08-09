#include <iostream>
#include <string>
#include "InputValidateLib.h"

using namespace std;

enum enWeekDayOrder { Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat };

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

enWeekDayOrder GetDayOfWeekOrder(stDate Date)
{
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;
    return (enWeekDayOrder) ((Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
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

bool IsEndOfWeek(enWeekDayOrder DayOfWeekOrder)
{
    return (DayOfWeekOrder == enWeekDayOrder::Sat);
}

bool IsWeekEnd(enWeekDayOrder DayOfWeekOrder)
{
    return (DayOfWeekOrder == enWeekDayOrder::Fri || DayOfWeekOrder == enWeekDayOrder::Sat);
}

bool IsBusinessDay(enWeekDayOrder DayOfWeekOrder)
{
    return !IsWeekEnd(DayOfWeekOrder);
}

short GetDaysUntilEndOfWeek(enWeekDayOrder DayOfWeekOrder)
{
    return 6 - DayOfWeekOrder;
}

short GetDaysUntilEndOfMonth(stDate Date)
{
    return GetTotalDaysInMonth(Date.Year, Date.Month) - Date.Day + 1;
}

short GetDaysUntilEndOfYear(stDate Date)
{
    return GetTotalDaysInYear(Date.Year) - GetNumberOfDaysFromTheBeginingOfTheYear(Date) + 1;
}

int main()
{
    stDate Date = GetSystemDate();
    enWeekDayOrder DayOfWeekOrder = GetDayOfWeekOrder(Date);

    cout << "Today is " << GetWeekDayName(DayOfWeekOrder) << " , ";
    PrintDate(Date);


    cout << "\n\nIs it End of Week?\n";
    if (IsEndOfWeek(DayOfWeekOrder))
        cout << "Yes it is Saturday, it is the end of the week.";
    else
        cout << "No, it is NOT the end of the week.";

    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(DayOfWeekOrder))
        cout << "Yes, it is the weekend.";
    else
        cout << "No today is " <<
        GetWeekDayName(DayOfWeekOrder) << ", Not a weekend.";

    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(DayOfWeekOrder))
        cout << "Yes, it is.";
    else
        cout << "No, it is NOT.";


    cout << "\n\nDays until end of week : " <<
    GetDaysUntilEndOfWeek(DayOfWeekOrder) << " Day(s).";
    cout << "\nDays until end of month : " <<
    GetDaysUntilEndOfMonth(Date) << " Day(s).";
    cout << "\nDays until end of year : " <<
    GetDaysUntilEndOfYear(Date) << " Day(s).";

    return 0;
}