#include <iostream>
#include <cassert>
#include "clsDate.h"
#include "clsPeriod.h"

using namespace std;

// ============================================================================
// 1. SECTION: TESTING ALL CONSTRUCTORS & GETTERS / SETTERS
// ============================================================================
void TestConstructorsAndGettersSetters()
{
    cout << "\n==================================================\n";
    cout << "  1. TESTING CONSTRUCTORS, GETTERS & SETTERS      \n";
    cout << "==================================================\n";

    // Default Constructor (System Date)
    clsDate Date1;
    cout << "Default Constructor (System Date): " << Date1.DateToString() << endl;

    // String Constructor
    clsDate Date2("25/12/2025");
    cout << "String Constructor (\"25/12/2025\"): " << Date2.DateToString() << endl;

    // Direct Parameters Constructor
    clsDate Date3(15, 8, 2026);
    cout << "Direct Params Constructor (15, 8, 2026): " << Date3.DateToString() << endl;

    // Day Order In Year Constructor (Day 60 in 2024 -> Feb 29 - Leap Year)
    clsDate Date4(60, 2024);
    cout << "Day 60 in Year 2024 (Leap): " << Date4.DateToString() << endl;

    // Setters Test
    Date1.SetDay(1);
    Date1.SetMonth(1);
    Date1.SetYear(2030);
    cout << "After Setters (1/1/2030) -> Day: " << Date1.GetDay() 
         << ", Month: " << Date1.GetMonth() 
         << ", Year: " << Date1.GetYear() << endl;
}

// ============================================================================
// 2. SECTION: TESTING FORMATTING & CONVERSIONS
// ============================================================================
void TestFormattingAndConversions()
{
    cout << "\n==================================================\n";
    cout << "  2. TESTING FORMATTING & STRING CONVERSIONS      \n";
    cout << "==================================================\n";

    clsDate Date(5, 9, 2026);

    cout << "DateToString (Static): " << clsDate::DateToString(Date) << endl;
    cout << "DateToString (Member): " << Date.DateToString() << endl;

    clsDate ParsedDate = clsDate::StringToDate("10/11/2026");
    cout << "StringToDate (\"10/11/2026\"): " << ParsedDate.DateToString() << endl;

    // Format Date Variations
    cout << "Format 'dd/mm/yyyy': " << Date.FormatDate("dd/mm/yyyy") << endl;
    cout << "Format 'yyyy-mm-dd': " << Date.FormatDate("yyyy-mm-dd") << endl;
    cout << "Format 'Day: dd, Month: mm, Year: yyyy': " 
         << Date.FormatDate("Day: dd, Month: mm, Year: yyyy") << endl;
}

// ============================================================================
// 3. SECTION: TESTING VALIDATION & SYSTEM DATE
// ============================================================================
void TestValidationAndSystemDate()
{
    cout << "\n==================================================\n";
    cout << "  3. TESTING VALIDATION & SYSTEM DATE             \n";
    cout << "==================================================\n";

    cout << "System Date: " << clsDate::GetSystemDate().DateToString() << endl;

    // Valid Dates
    clsDate Valid1(29, 2, 2024); // Valid leap year
    clsDate Invalid1(29, 2, 2025); // Invalid non-leap year
    clsDate Invalid2(31, 4, 2026); // April has 30 days only

    cout << "Is 29/02/2024 Valid? " << (Valid1.IsValid() ? "Yes" : "No") << endl;
    cout << "Is 29/02/2025 Valid? " << (Invalid1.IsValid() ? "Yes" : "No") << endl;
    cout << "Is 31/04/2026 Valid? " << (clsDate::IsValidDate(Invalid2) ? "Yes" : "No") << endl;
}

// ============================================================================
// 4. SECTION: TESTING LEAP YEAR & CALENDAR CALCULATIONS
// ============================================================================
void TestCalendarCalculations()
{
    cout << "\n==================================================\n";
    cout << "  4. TESTING LEAP YEAR & TIME CALCULATIONS        \n";
    cout << "==================================================\n";

    short LeapYear = 2024;
    short NormalYear = 2025;

    cout << "Is " << LeapYear << " Leap Year? " << (clsDate::isLeapYear(LeapYear) ? "Yes" : "No") << endl;
    cout << "Is " << NormalYear << " Leap Year? " << (clsDate::isLeapYear(NormalYear) ? "Yes" : "No") << endl;

    cout << "\nYear " << LeapYear << " Calculations:\n";
    cout << " - Total Days   : " << clsDate::NumberOfDaysInAYear(LeapYear) << endl;
    cout << " - Total Hours  : " << clsDate::NumberOfHoursInAYear(LeapYear) << endl;
    cout << " - Total Minutes: " << clsDate::NumberOfMinutesInAYear(LeapYear) << endl;
    cout << " - Total Seconds: " << clsDate::NumberOfSecondsInAYear(LeapYear) << endl;

    cout << "\nFeb " << LeapYear << " Days: " << clsDate::NumberOfDaysInAMonth(2, LeapYear) << endl;
    cout << "Feb " << NormalYear << " Days: " << clsDate::NumberOfDaysInAMonth(2, NormalYear) << endl;
    cout << "Feb Hours: " << clsDate::NumberOfHoursInAMonth(2, LeapYear) << endl;
    cout << "Feb Minutes: " << clsDate::NumberOfMinutesInAMonth(2, LeapYear) << endl;
    cout << "Feb Seconds: " << clsDate::NumberOfSecondsInAMonth(2, LeapYear) << endl;

    clsDate TestDate(8, 8, 2026);
    cout << "\nDay Name for 08/08/2026: " << TestDate.DayShortName() << " (Order: " << TestDate.DayOfWeekOrder() << ")" << endl;
    cout << "Month Short Name for Month 8: " << TestDate.MonthShortName() << endl;

    // Calendar Prints
    cout << "\nPrinting Month Calendar (August 2026):";
    clsDate::PrintMonthCalendar(8, 2026);
}

// ============================================================================
// 5. SECTION: TESTING COMPARISONS & DIFFERENCES
// ============================================================================
void TestComparisonsAndDifferences()
{
    cout << "\n==================================================\n";
    cout << "  5. TESTING COMPARISONS & DIFFERENCES            \n";
    cout << "==================================================\n";

    clsDate D1(1, 1, 2026);
    clsDate D2(10, 1, 2026);
    clsDate D3(1, 1, 2026);

    cout << "D1: " << D1.DateToString() << " | D2: " << D2.DateToString() << endl;
    cout << "Is D1 Before D2? " << (D1.IsDateBeforeDate2(D2) ? "Yes" : "No") << endl;
    cout << "Is D1 Equal D3?  " << (D1.IsDateEqualDate2(D3) ? "Yes" : "No") << endl;
    cout << "Is D2 After D1?  " << (D2.IsDateAfterDate2(D1) ? "Yes" : "No") << endl;

    cout << "Compare D1 & D2 Enum Result: " << D1.CompareDates(D2) << " (-1: Before, 0: Equal, 1: After)\n";

    // Difference in days (Normal & Swapped)
    cout << "\nDiff Days (D1 to D2 - Excl End): " << clsDate::GetDifferenceInDays(D1, D2) << endl;
    cout << "Diff Days (D1 to D2 - Incl End): " << clsDate::GetDifferenceInDays(D1, D2, true) << endl;
    cout << "Diff Days Swapped (D2 to D1 - Negative Check): " << clsDate::GetDifferenceInDays(D2, D1) << endl;

    // Days Order
    cout << "Days From Beginning Of Year for 10/01/2026: " << D2.DaysFromTheBeginingOfTheYear() << endl;

    // Age Calculation
    clsDate BirthDate(1, 1, 2000);
    cout << "My Age In Days (From 01/01/2000 to System Date): " << clsDate::CalculateMyAgeInDays(BirthDate) << endl;
}

// ============================================================================
// 6. SECTION: TESTING INCREMENT / DECREMENT OPERATIONS
// ============================================================================
void TestIncrementsAndDecrements()
{
    cout << "\n==================================================\n";
    cout << "  6. TESTING INCREMENT & DECREMENT OPERATIONS     \n";
    cout << "==================================================\n";

    clsDate D(28, 2, 2024); // Leap year boundary
    cout << "Base Date: " << D.DateToString() << endl;

    D.AddOneDay();
    cout << "Add 1 Day (Leap Feb 29): " << D.DateToString() << endl;

    D.AddOneDay();
    cout << "Add 1 Day (March 1): " << D.DateToString() << endl;

    D.IncreaseDateByOneWeek();
    cout << "Increase 1 Week: " << D.DateToString() << endl;

    D.IncreaseDateByXWeeks(2);
    cout << "Increase 2 Weeks: " << D.DateToString() << endl;

    D.IncreaseDateByXDays(10);
    cout << "Increase 10 Days: " << D.DateToString() << endl;

    D.IncreaseDateByOneMonth();
    cout << "Increase 1 Month: " << D.DateToString() << endl;

    D.IncreaseDateByXMonths(5);
    cout << "Increase 5 Months: " << D.DateToString() << endl;

    D.IncreaseDateByOneYear();
    cout << "Increase 1 Year: " << D.DateToString() << endl;

    D.IncreaseDateByXYears(5);
    cout << "Increase 5 Years: " << D.DateToString() << endl;

    D.IncreaseDateByOneDecade();
    cout << "Increase 1 Decade: " << D.DateToString() << endl;

    D.IncreaseDateByXDecades(2);
    cout << "Increase 2 Decades: " << D.DateToString() << endl;

    D.IncreaseDateByOneCentury();
    cout << "Increase 1 Century: " << D.DateToString() << endl;

    D.IncreaseDateByOneMillennium();
    cout << "Increase 1 Millennium: " << D.DateToString() << endl;

    cout << "\n--- Decrement Operations ---\n";
    D.DecreaseDateByOneMillennium();
    cout << "Decrease 1 Millennium: " << D.DateToString() << endl;

    D.DecreaseDateByOneCentury();
    cout << "Decrease 1 Century: " << D.DateToString() << endl;

    D.DecreaseDateByXDecades(2);
    cout << "Decrease 2 Decades: " << D.DateToString() << endl;

    D.DecreaseDateByOneDecade();
    cout << "Decrease 1 Decade: " << D.DateToString() << endl;

    D.DecreaseDateByXYears(5);
    cout << "Decrease 5 Years: " << D.DateToString() << endl;

    D.DecreaseDateByOneYear();
    cout << "Decrease 1 Year: " << D.DateToString() << endl;

    D.DecreaseDateByXMonths(5);
    cout << "Decrease 5 Months: " << D.DateToString() << endl;

    D.DecreaseDateByOneMonth();
    cout << "Decrease 1 Month: " << D.DateToString() << endl;

    D.DecreaseDateByXDays(10);
    cout << "Decrease 10 Days: " << D.DateToString() << endl;

    D.DecreaseDateByXWeeks(2);
    cout << "Decrease 2 Weeks: " << D.DateToString() << endl;

    D.DecreaseDateByOneWeek();
    cout << "Decrease 1 Week: " << D.DateToString() << endl;

    D.DecreaseDateByOneDay();
    cout << "Decrease 1 Day: " << D.DateToString() << endl;
}

// ============================================================================
// 7. SECTION: TESTING BUSINESS DAYS & VACATIONS
// ============================================================================
void TestBusinessDaysAndVacations()
{
    cout << "\n==================================================\n";
    cout << "  7. TESTING BUSINESS DAYS & VACATIONS            \n";
    cout << "==================================================\n";

    clsDate Friday(7, 8, 2026);  // Friday
    clsDate Saturday(8, 8, 2026); // Saturday
    clsDate Monday(10, 8, 2026);  // Monday

    cout << "07/08/2026 (Fri) - Is End Of Week? " << (Friday.IsEndOfWeek() ? "Yes" : "No") << endl;
    cout << "08/08/2026 (Sat) - Is End Of Week? " << (Saturday.IsEndOfWeek() ? "Yes" : "No") << endl;

    cout << "07/08/2026 (Fri) - Is Weekend? " << (Friday.IsWeekEnd() ? "Yes" : "No") << endl;
    cout << "10/08/2026 (Mon) - Is Weekend? " << (Monday.IsWeekEnd() ? "Yes" : "No") << endl;

    cout << "10/08/2026 (Mon) - Is Business Day? " << (Monday.IsBusinessDay() ? "Yes" : "No") << endl;

    cout << "Days Until End Of Week from Mon (10/08): " << Monday.DaysUntilTheEndOfWeek() << endl;
    cout << "Days Until End Of Month from Mon (10/08): " << Monday.DaysUntilTheEndOfMonth() << endl;
    cout << "Days Until End Of Year from Mon (10/08): " << Monday.DaysUntilTheEndOfYear() << endl;

    // Vacation calculations
    clsDate VacationStart(2, 8, 2026); // Sunday
    clsDate VacationEnd(13, 8, 2026);  // Thursday

    cout << "\nVacation Business Days (02/08 to 13/08): " 
         << clsDate::CalculateVacationDays(VacationStart, VacationEnd) << " days" << endl;

    short VacationDays = 10;
    clsDate ReturnDate = clsDate::CalculateVacationReturnDate(VacationStart, VacationDays);
    cout << "Vacation Start: " << VacationStart.DateToString() << " for (" << VacationDays << ") business days." << endl;
    cout << "Return Date (Skipping Weekends): " << ReturnDate.DateToString() << endl;
}

// ============================================================================
// 8. SECTION: TESTING CLSPERIOD CLASS (ALL FUNCTIONS)
// ============================================================================
void TestPeriodClassFull()
{
    cout << "\n==================================================\n";
    cout << "  8. TESTING CLSPERIOD CLASS (ALL FUNCTIONS)     \n";
    cout << "==================================================\n";

    clsPeriod P1(clsDate(1, 1, 2026), clsDate(10, 1, 2026));
    clsPeriod P2(clsDate(5, 1, 2026), clsDate(15, 1, 2026));  // Overlaps P1
    clsPeriod P3(clsDate(20, 1, 2026), clsDate(30, 1, 2026)); // No overlap with P1

    cout << "--- Period 1 ---\n";
    P1.Print();

    cout << "--- Period 2 ---\n";
    P2.Print();

    cout << "--- Period 3 ---\n";
    P3.Print();

    // Setters & Getters
    clsPeriod P4(clsDate(1, 1, 2000), clsDate(2, 2, 2000));
    P4.SetStartDate(clsDate(1, 5, 2026));
    P4.SetEndDate(clsDate(10, 5, 2026));
    cout << "Period 4 Getters -> Start: " << P4.StartDate().DateToString() 
         << " | End: " << P4.EndDate().DateToString() << endl;

    // Length
    cout << "\nP1 Length (Excl End): " << P1.GetPeriodLengthInDays() << " days" << endl;
    cout << "P1 Length (Incl End): " << P1.GetPeriodLengthInDays(true) << " days" << endl;

    // Overlaps
    cout << "\nIs P1 Overlapping P2 (Static)? " << (clsPeriod::IsOverlapPeriods(P1, P2) ? "Yes" : "No") << endl;
    cout << "Is P1 Overlapping P2 (Member)? " << (P1.IsOverLapWith(P2) ? "Yes" : "No") << endl;
    cout << "Is P1 Overlapping P3? " << (P1.IsOverLapWith(P3) ? "Yes" : "No") << endl;

    // Overlap Days Count
    cout << "\nOverlap Days P1 & P2 (Excl End): " << P1.GetOverlapDays(P2) << " days" << endl;
    cout << "Overlap Days P1 & P2 (Incl End): " << P1.GetOverlapDays(P2, true) << " days" << endl;
    cout << "Overlap Days P1 & P3: " << P1.GetOverlapDays(P3) << " days" << endl;

    // Date inside Period
    clsDate InsideDate(7, 1, 2026);
    clsDate OutsideDate(15, 1, 2026);

    cout << "\nIs 07/01/2026 inside P1? " << (P1.IsDateInPeriod(InsideDate) ? "Yes" : "No") << endl;
    cout << "Is 15/01/2026 inside P1? " << (P1.IsDateInPeriod(OutsideDate) ? "Yes" : "No") << endl;
}

// ============================================================================
// MAIN EXECUTION
// ============================================================================
int main()
{
    TestConstructorsAndGettersSetters();
    TestFormattingAndConversions();
    TestValidationAndSystemDate();
    TestCalendarCalculations();
    TestComparisonsAndDifferences();
    TestIncrementsAndDecrements();
    TestBusinessDaysAndVacations();
    TestPeriodClassFull();

    cout << "\n==================================================\n";
    cout << "   ALL TESTS EXECUTED AND PASSED SUCCESSFULLY!    \n";
    cout << "==================================================\n";

    return 0;
}