#include "PeriodLib.h"

// Constructor
PeriodLib::PeriodLib(const DateLib &StartDate, const DateLib &DateTo)
    : _StartDate(StartDate), _EndDate(DateTo)
{
}

// Setters
void PeriodLib::SetStartDate(const DateLib &Date) { _StartDate = Date; }
void PeriodLib::SetEndDate(const DateLib &Date) { _EndDate = Date; }

// Getters
DateLib PeriodLib::StartDate() const { return _StartDate; }
DateLib PeriodLib::EndDate() const { return _EndDate; }

// Overlap Operations
bool PeriodLib::IsOverlapPeriods(const PeriodLib &Period1, const PeriodLib &Period2)
{
    return !((DateLib::CompareDates(Period2._EndDate, Period1._StartDate) == DateLib::enCompareDates::Before) ||
             (DateLib::CompareDates(Period2._StartDate, Period1._EndDate) == DateLib::enCompareDates::After));
}

bool PeriodLib::IsOverLapWith(const PeriodLib &Period2) const
{
    return IsOverlapPeriods(*this, Period2);
}

// Period Length
int PeriodLib::GetPeriodLengthInDays(const PeriodLib &Period, bool IncludeEndDate)
{
    return DateLib::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludeEndDate);
}

int PeriodLib::GetPeriodLengthInDays(bool IncludeEndDate) const
{
    return GetPeriodLengthInDays(*this, IncludeEndDate);
}

// Date in Period
bool PeriodLib::IsDateInPeriod(const PeriodLib &Period, const DateLib &Date)
{
    return !(DateLib::CompareDates(Date, Period._StartDate) == DateLib::enCompareDates::Before ||
             DateLib::CompareDates(Date, Period._EndDate) == DateLib::enCompareDates::After);
}

bool PeriodLib::IsDateInPeriod(const DateLib &Date) const
{
    return IsDateInPeriod(*this, Date);
}

// Overlap Days Count
short PeriodLib::GetOverlapDays(const PeriodLib &Period1, const PeriodLib &Period2, bool IncludeEndDate)
{
    if (IsOverlapPeriods(Period1, Period2))
    {
        DateLib OverlapStart = DateLib::IsDate1BeforeDate2(Period2._StartDate, Period1._StartDate) ? Period1._StartDate : Period2._StartDate;
        DateLib OverlapEnd = DateLib::IsDate1BeforeDate2(Period1._EndDate, Period2._EndDate) ? Period1._EndDate : Period2._EndDate;

        return DateLib::GetDifferenceInDays(OverlapStart, OverlapEnd, IncludeEndDate);
    }

    return 0;
}

short PeriodLib::GetOverlapDays(const PeriodLib &Period2, bool IncludeEndDate) const
{
    return GetOverlapDays(*this, Period2, IncludeEndDate);
}

// UI / Print
void PeriodLib::Print() const
{
    cout << "Period Start: ";
    _StartDate.Print();
    cout << "\nPeriod End  : ";
    _EndDate.Print();
    cout << endl;
}