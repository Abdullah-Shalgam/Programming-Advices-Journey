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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        Date.Day = GetTotalDaysInMonth(Date.Year, Date.Month);
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short DaysToRemove)
{
    for (short i = 1; i <= DaysToRemove; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, short WeeksToRemove)
{
    for (short i = 1; i <= WeeksToRemove; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short MonthsToRemove)
{
    for (short i = 1; i <= MonthsToRemove; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXYears(stDate Date, short YearsToRemove)
{
    for (short i = 1; i <= YearsToRemove; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short YearsToRemove)
{
    Date.Year -= YearsToRemove;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    return DecreaseDateByXYearsFaster(Date, 10);
}

stDate DecreaseDateByXDecades(stDate Date, short DecadesToRemove)
{
    for (short i = 1; i <= DecadesToRemove; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short DecadesToRemove)
{
    Date.Year -= DecadesToRemove * 10;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    return DecreaseDateByXDecadesFaster(Date, 10);
}

stDate DecreaseDateByXCenturiesFaster(stDate Date, short CenturiesToRemove)
{
    Date.Year -= CenturiesToRemove * 100;

    short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    return DecreaseDateByXCenturiesFaster(Date, 10);
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\nDate After: \n\n\n";

    cout << "01-Subtracting One Day is: ";
    Date = DecreaseDateByOneDay(Date);
    PrintDate(Date);

    cout << "\n02-Subtracting 10 Days is: ";
    Date = DecreaseDateByXDays(Date, 10);
    PrintDate(Date);

    cout << "\n03-Subtracting One Week is: ";
    Date = DecreaseDateByOneWeek(Date);
    PrintDate(Date);

    cout << "\n04-Subtracting 10 Weeks is: ";
    Date = DecreaseDateByXWeeks(Date, 10);
    PrintDate(Date);

    cout << "\n05-Subtracting One Month is: ";
    Date = DecreaseDateByOneMonth(Date);
    PrintDate(Date);

    cout << "\n06-Subtracting 5 Months is: ";
    Date = DecreaseDateByXMonths(Date, 5);
    PrintDate(Date);

    cout << "\n07-Subtracting One Year is: ";
    Date = DecreaseDateByOneYear(Date);
    PrintDate(Date);

    cout << "\n08-Subtracting 10 Years is: ";
    Date = DecreaseDateByXYears(Date, 10);
    PrintDate(Date);

    cout << "\n09-Subtracting 10 Years (Faster) is: ";
    Date = DecreaseDateByXYearsFaster(Date, 10);
    PrintDate(Date);

    cout << "\n10-Subtracting One Decade is: ";
    Date = DecreaseDateByOneDecade(Date);
    PrintDate(Date);

    cout << "\n11-Subtracting 10 Decades is: ";
    Date = DecreaseDateByXDecades(Date, 10);
    PrintDate(Date);

    cout << "\n12-Subtracting 10 Decades (Faster) is: ";
    Date = DecreaseDateByXDecadesFaster(Date, 10);
    PrintDate(Date);
    
    cout << "\n13-Subtracting One Century is: ";
    Date = DecreaseDateByOneCentury(Date);
    PrintDate(Date);

    cout << "\n14-Subtracting One Millennium is: ";
    Date = DecreaseDateByOneMillennium(Date);
    PrintDate(Date);
    
    return 0;
}