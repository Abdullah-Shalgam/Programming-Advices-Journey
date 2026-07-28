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

stDate GetDateFromDayOrderInYear(short DayOrderInYear, short year)
{
    short DaysInCurrentMonth = 0;

    for (short Month = 1; Month <= 12; Month++)
    {
        DaysInCurrentMonth = GetTotalDaysInMonth(year, Month);

        if (DayOrderInYear <= DaysInCurrentMonth)
        {
            return {DayOrderInYear, Month, year};
        }
        
        DayOrderInYear -= DaysInCurrentMonth;
    }

    return {0, 0, year};
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

stDate IncreaseDateByXDays(stDate Date, short DaysToAdd)
{
    for (short i = 1; i <= DaysToAdd; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short WeeksToAdd)
{
    for (short i = 1; i <= WeeksToAdd; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short MonthsToAdd)
{
    for (short i = 1; i <= MonthsToAdd; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short YearsToAdd)
{
    for (short i = 1; i <= YearsToAdd; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short YearsToAdd)
{
    Date.Year += YearsToAdd;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    return IncreaseDateByXYearsFaster(Date, 10);
}

stDate IncreaseDateByXDecades(stDate Date, short DecadesToAdd)
{
    for (short i = 1; i <= DecadesToAdd; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short DecadesToAdd)
{
    Date.Year += DecadesToAdd * 10;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    return IncreaseDateByXDecadesFaster(Date, 10);
}

stDate IncreaseDateByXCenturiesFaster(stDate Date, short CenturiesToAdd)
{
    Date.Year += CenturiesToAdd * 100;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    return IncreaseDateByXCenturiesFaster(Date, 10);
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\nDate After: \n\n\n";

    cout << "01-Adding One Day is: ";
    Date = IncreaseDateByOneDay(Date);
    PrintDate(Date);

    cout << "\n02-Adding 10 Days is: ";
    Date = IncreaseDateByXDays(Date, 10);
    PrintDate(Date);

    cout << "\n03-Adding One Week is: ";
    Date = IncreaseDateByOneWeek(Date);
    PrintDate(Date);

    cout << "\n04-Adding 10 Weeks is: ";
    Date = IncreaseDateByXWeeks(Date, 10);
    PrintDate(Date);

    cout << "\n05-Adding One Month is: ";
    Date = IncreaseDateByOneMonth(Date);
    PrintDate(Date);

    cout << "\n06-Adding 5 Months is: ";
    Date = IncreaseDateByXMonths(Date, 5);
    PrintDate(Date);

    cout << "\n07-Adding One Year is: ";
    Date = IncreaseDateByOneYear(Date);
    PrintDate(Date);

    cout << "\n08-Adding 10 Years is: ";
    Date = IncreaseDateByXYears(Date, 10);
    PrintDate(Date);

    cout << "\n09-Adding 10 Years (Faster) is: ";
    Date = IncreaseDateByXYearsFaster(Date, 10);
    PrintDate(Date);

    cout << "\n10-Adding One Decade is: ";
    Date = IncreaseDateByOneDecade(Date);
    PrintDate(Date);

    cout << "\n11-Adding 10 Decades is: ";
    Date = IncreaseDateByXDecades(Date, 10);
    PrintDate(Date);

    cout << "\n12-Adding 10 Decades (Faster) is: ";
    Date = IncreaseDateByXDecadesFaster(Date, 10);
    PrintDate(Date);
    
    cout << "\n13-Adding One Century is: ";
    Date = IncreaseDateByOneCentury(Date);
    PrintDate(Date);

    cout << "\n14-Adding One Millennium is: ";
    Date = IncreaseDateByOneMillennium(Date);
    PrintDate(Date);
    
    return 0;
}