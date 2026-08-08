#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "MyStringLib.h"

using namespace std;

/**
 * ============================================================================
 * Class: clsDate
 * Description: مكتبة متكاملة للتعامل مع التواريخ، الحسابات التقويمية، 
 *              المقارنات، وحساب الإجازات وأيام العمل.
 * ============================================================================
 */
class clsDate
{
public:
    // حالة المقارنة بين تاريخين
    enum enCompareDates { Before = -1, Equal = 0, After = 1 };

private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:

    // =========================================================================
    // 1. Constructors (دوال البناء)
    // =========================================================================

    // المنشئ الافتراضي: يجلب تاريخ النظام الحالي
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    // بناء التاريخ من نص (مثال: "15/8/2026")
    clsDate(const string& DateString)
    {
        *this = StringToDate(DateString);
    }

    // بناء التاريخ بتمرير اليوم والشهر والسنة مباشرة
    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    // بناء التاريخ من رقم اليوم خلال السنة (مثال: اليوم رقم 200 في سنة 2026)
    clsDate(short DateOrderInYear, short Year)
    {
        *this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
    }

    // =========================================================================
    // 2. Setters & Getters (دوال التعيين والاسترجاع القياسية)
    // =========================================================================

    void SetDay(short Day) { _Day = Day; }
    short GetDay() const { return _Day; }

    void SetMonth(short Month) { _Month = Month; }
    short GetMonth() const { return _Month; }

    void SetYear(short Year) { _Year = Year; }
    short GetYear() const { return _Year; }

    // =========================================================================
    // 3. Printing & String Conversions (دوال الطباعة والتحويل)
    // =========================================================================

    static string DateToString(const clsDate& Date)
    {
        return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
    }

    string DateToString() const
    {
        return DateToString(*this);
    }

    static clsDate StringToDate(const string& DateString, const string& Delim = "/")
    {
        vector<string> vDate = MyStringLib::SplitString(DateString, Delim);
        return clsDate(stoi(vDate[0]), stoi(vDate[1]), stoi(vDate[2]));
    }

    void Print() const
    {
        cout << DateToString() << endl;
    }

    // تنسيق التاريخ بحسب القالب المطلوب (مثال: "dd/mm/yyyy")
    static string FormatDate(const clsDate& Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = DateFormat;
        FormattedDateString = MyStringLib::ReplaceWord(FormattedDateString, "dd", to_string(Date.GetDay()));
        FormattedDateString = MyStringLib::ReplaceWord(FormattedDateString, "mm", to_string(Date.GetMonth()));
        FormattedDateString = MyStringLib::ReplaceWord(FormattedDateString, "yyyy", to_string(Date.GetYear()));
        return FormattedDateString;
    }

    string FormatDate(const string& DateFormat = "dd/mm/yyyy") const
    {
        return FormatDate(*this, DateFormat);
    }

    // =========================================================================
    // 4. System Date & Validation (تاريخ النظام والتحقق من صحة التاريخ)
    // =========================================================================

    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static bool IsValidDate(const clsDate& Date)
    {
        if (Date.GetDay() < 1 || Date.GetDay() > 31) return false;
        if (Date.GetMonth() < 1 || Date.GetMonth() > 12) return false;

        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth) return false;

        return true;
    }

    bool IsValid() const
    {
        return IsValidDate(*this);
    }

    // =========================================================================
    // 5. Year / Month / Day Time Calculations (حسابات الأيام والشهور والساعات)
    // =========================================================================

    static bool isLeapYear(short Year)
    {
        return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
    }

    bool isLeapYear() const
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear() const
    {
        return NumberOfDaysInAYear(_Year);
    }

    static short NumberOfHoursInAYear(short Year) { return NumberOfDaysInAYear(Year) * 24; }
    short NumberOfHoursInAYear() const { return NumberOfHoursInAYear(_Year); }

    static int NumberOfMinutesInAYear(short Year) { return NumberOfHoursInAYear(Year) * 60; }
    int NumberOfMinutesInAYear() const { return NumberOfMinutesInAYear(_Year); }

    static int NumberOfSecondsInAYear(short Year) { return NumberOfMinutesInAYear(Year) * 60; }
    int NumberOfSecondsInAYear() const { return NumberOfSecondsInAYear(_Year); }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short NumberOfDaysInAMonth() const
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    static short NumberOfHoursInAMonth(short Month, short Year) { return NumberOfDaysInAMonth(Month, Year) * 24; }
    short NumberOfHoursInAMonth() const { return NumberOfHoursInAMonth(_Month, _Year); }

    static int NumberOfMinutesInAMonth(short Month, short Year) { return NumberOfHoursInAMonth(Month, Year) * 60; }
    int NumberOfMinutesInAMonth() const { return NumberOfMinutesInAMonth(_Month, _Year); }

    static int NumberOfSecondsInAMonth(short Month, short Year) { return NumberOfMinutesInAMonth(Month, Year) * 60; }
    int NumberOfSecondsInAMonth() const { return NumberOfSecondsInAMonth(_Month, _Year); }

    // =========================================================================
    // 6. Calendar & Short Names (التقويم والأسماء المختصرة)
    // =========================================================================

    // ترجع ترتيب اليوم في الأسبوع (0 = Sun, 1 = Mon, ..., 6 = Sat)
    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder() const
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return arrDayNames[DayOfWeekOrder];
    }

    string DayShortName() const
    {
        return DayShortName(DayOfWeekOrder());
    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[MonthNumber - 1];
    }

    string MonthShortName() const
    {
        return MonthShortName(_Month);
    }

    // طباعة تقويم شهر محدد
    static void PrintMonthCalendar(short Month, short Year)
    {
        int current = DayOfWeekOrder(1, Month, Year);
        int NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  _________________________________\n");
    }

    void PrintMonthCalendar() const
    {
        PrintMonthCalendar(_Month, _Year);
    }

    // طباعة تقويم السنة كاملة
    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
    }

    void PrintYearCalendar() const
    {
        PrintYearCalendar(_Year);
    }

    // =========================================================================
    // 7. Days Order & Conversions (حساب ترتيب الأيام تحويلها)
    // =========================================================================

    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short TotalDays = 0;
        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Year);
        }
        TotalDays += Day;
        return TotalDays;
    }

    short DaysFromTheBeginingOfTheYear() const
    {
        return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date.SetYear(Year);
        Date.SetMonth(1);

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.SetMonth(Date.GetMonth() + 1);
            }
            else
            {
                Date.SetDay(RemainingDays);
                break;
            }
        }
        return Date;
    }

    void AddDays(short Days)
    {
        short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;
                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }
        }
    }

    // =========================================================================
    // 8. Date Comparisons (دوال المقارنة بين التواريخ)
    // =========================================================================

    static bool IsDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2)
    {
        return (Date1.GetYear() < Date2.GetYear()) ? true :
            ((Date1.GetYear() == Date2.GetYear()) ? (Date1.GetMonth() < Date2.GetMonth() ? true :
            (Date1.GetMonth() == Date2.GetMonth() ? Date1.GetDay() < Date2.GetDay() : false)) : false);
    }

    bool IsDateBeforeDate2(const clsDate& Date2) const
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
    {
        return (Date1.GetYear() == Date2.GetYear() && Date1.GetMonth() == Date2.GetMonth() && Date1.GetDay() == Date2.GetDay());
    }

    bool IsDateEqualDate2(const clsDate& Date2) const
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(const clsDate& Date1, const clsDate& Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(const clsDate& Date2) const
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    static enCompareDates CompareDates(const clsDate& Date1, const clsDate& Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2)) return enCompareDates::Before;
        if (IsDate1EqualDate2(Date1, Date2)) return enCompareDates::Equal;
        return enCompareDates::After;
    }

    enCompareDates CompareDates(const clsDate& Date2) const
    {
        return CompareDates(*this, Date2);
    }

    // =========================================================================
    // 9. Date Boundary Checks (دوال الفحص والتحقق من الحدود)
    // =========================================================================

    static bool IsLastDayInMonth(const clsDate& Date)
    {
        return (Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()));
    }

    bool IsLastDayInMonth() const
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear() const
    {
        return IsLastMonthInYear(_Month);
    }

    // =========================================================================
    // 10. Operations: Add / Swap / Differences (العمليات والفروقات بين التواريخ)
    // =========================================================================

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.GetMonth()))
            {
                Date.SetMonth(1);
                Date.SetDay(1);
                Date.SetYear(Date.GetYear() + 1);
            }
            else
            {
                Date.SetDay(1);
                Date.SetMonth(Date.GetMonth() + 1);
            }
        }
        else
        {
            Date.SetDay(Date.GetDay() + 1);
        }

        return Date;
    }

    void AddOneDay()
    {
        *this = AddOneDay(*this);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    int GetDifferenceInDays(const clsDate& Date2, bool IncludeEndDay = false) const
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static int CalculateMyAgeInDays(const clsDate& DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    // =========================================================================
    // 11. Increase Dates (دوال زيادة التواريخ)
    // =========================================================================

    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = AddOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate IncreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.GetMonth() == 12)
        {
            Date.SetMonth(1);
            Date.SetYear(Date.GetYear() + 1);
        }
        else
        {
            Date.SetMonth(Date.GetMonth() + 1);
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > NumberOfDaysInCurrentMonth)
        {
            Date.SetDay(NumberOfDaysInCurrentMonth);
        }

        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = AddOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDays(short Days)
    {
        IncreaseDateByXDays(Days, *this);
    }

    static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date.SetYear(Date.GetYear() + 1);
        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
        {
            Date.SetDay(DaysInMonth);
        }
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.SetYear(Date.GetYear() + Years);
        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
        {
            Date.SetDay(DaysInMonth);
        }
        return Date;
    }

    void IncreaseDateByXYears(short Years)
    {
        IncreaseDateByXYears(Years, *this);
    }

    static clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        return IncreaseDateByXYears(10, Date);
    }

    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(short Decades, clsDate& Date)
    {
        return IncreaseDateByXYears(Decades * 10, Date);
    }

    void IncreaseDateByXDecades(short Decades)
    {
        IncreaseDateByXDecades(Decades, *this);
    }

    static clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        return IncreaseDateByXYears(100, Date);
    }

    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        return IncreaseDateByXYears(1000, Date);
    }

    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    // =========================================================================
    // 12. Decrease Dates (دوال إنقاص التواريخ)
    // =========================================================================

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.GetDay() == 1)
        {
            if (Date.GetMonth() == 1)
            {
                Date.SetMonth(12);
                Date.SetDay(31);
                Date.SetYear(Date.GetYear() - 1);
            }
            else
            {
                Date.SetMonth(Date.GetMonth() - 1);
                Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()));
            }
        }
        else
        {
            Date.SetDay(Date.GetDay() - 1);
        }

        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByXDays(short Days)
    {
        DecreaseDateByXDays(Days, *this);
    }

    static clsDate DecreaseDateByOneWeek(clsDate& Date)
    {
        return DecreaseDateByXDays(7, Date);
    }

    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks)
    {
        DecreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate DecreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.GetMonth() == 1)
        {
            Date.SetMonth(12);
            Date.SetYear(Date.GetYear() - 1);
        }
        else
            Date.SetMonth(Date.GetMonth() - 1);

        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
        {
            Date.SetDay(DaysInMonth);
        }

        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonths(short Months)
    {
        DecreaseDateByXMonths(Months, *this);
    }

    static clsDate DecreaseDateByOneYear(clsDate& Date)
    {
        Date.SetYear(Date.GetYear() - 1);
        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
        {
            Date.SetDay(DaysInMonth);
        }
        return Date;
    }

    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.SetYear(Date.GetYear() - Years);
        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
        {
            Date.SetDay(DaysInMonth);
        }
        return Date;
    }

    void DecreaseDateByXYears(short Years)
    {
        DecreaseDateByXYears(Years, *this);
    }

    static clsDate DecreaseDateByOneDecade(clsDate& Date)
    {
        return DecreaseDateByXYears(10, Date);
    }

    void DecreaseDateByOneDecade()
    {
        DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
    {
        return DecreaseDateByXYears(Decades * 10, Date);
    }

    void DecreaseDateByXDecades(short Decades)
    {
        DecreaseDateByXDecades(Decades, *this);
    }

    static clsDate DecreaseDateByOneCentury(clsDate& Date)
    {
        return DecreaseDateByXYears(100, Date);
    }

    void DecreaseDateByOneCentury()
    {
        DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date)
    {
        return DecreaseDateByXYears(1000, Date);
    }

    void DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(*this);
    }

    // =========================================================================
    // 13. Business Days & Vacations (حساب أيام العمل والإجازات)
    // =========================================================================

    static bool IsEndOfWeek(const clsDate& Date)
    {
        return DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()) == 6;
    }

    bool IsEndOfWeek() const
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(const clsDate& Date)
    {
        short DayIndex = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsWeekEnd() const
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(const clsDate& Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay() const
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(const clsDate& Date)
    {
        return 6 - DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
    }

    short DaysUntilTheEndOfWeek() const
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(const clsDate& Date1)
    {
        clsDate EndOfMonthDate;
        EndOfMonthDate.SetDay(NumberOfDaysInAMonth(Date1.GetMonth(), Date1.GetYear()));
        EndOfMonthDate.SetMonth(Date1.GetMonth());
        EndOfMonthDate.SetYear(Date1.GetYear());

        return GetDifferenceInDays(Date1, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfMonth() const
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(const clsDate& Date1)
    {
        clsDate EndOfYearDate;
        EndOfYearDate.SetDay(31);
        EndOfYearDate.SetMonth(12);
        EndOfYearDate.SetYear(Date1.GetYear());

        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short DaysUntilTheEndOfYear() const
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }

        return Days;
    }

    static short CalculateVacationDays(const clsDate& DateFrom, const clsDate& DateTo)
    {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        while (VacationDays > 0)
        {
            if (IsBusinessDay(DateFrom))
                VacationDays--;

            DateFrom = AddOneDay(DateFrom);
        }

        while (IsWeekEnd(DateFrom))
        {
            DateFrom = AddOneDay(DateFrom);
        }

        return DateFrom;
    }
};