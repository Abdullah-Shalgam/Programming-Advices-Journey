#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsPeriod
{
private:
    clsDate _StartDate;
    clsDate _EndDate;

public:

    clsPeriod(const clsDate& StartDate, const clsDate& DateTo)
        : _StartDate(StartDate), _EndDate(DateTo)
    {
    }

    // Setters
    void SetStartDate(const clsDate& Date) { _StartDate = Date; }
    void SetEndDate(const clsDate& Date) { _EndDate = Date; }

    // Getters
    clsDate StartDate() const { return _StartDate; }
    clsDate EndDate() const { return _EndDate; }

    // --- Overlap Operations ---

    static bool IsOverlapPeriods(const clsPeriod& Period1, const clsPeriod& Period2)
    {
        return !((clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enCompareDates::Before) ||
                (clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enCompareDates::After));
    }

    bool IsOverLapWith(const clsPeriod& Period2) const
    {
        return IsOverlapPeriods(*this, Period2);
    }

    // --- Period Length ---

    static int GetPeriodLengthInDays(const clsPeriod& Period, bool IncludeEndDate = false)
    {
        return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludeEndDate);
    }

    int GetPeriodLengthInDays(bool IncludeEndDate = false) const
    {
        return GetPeriodLengthInDays(*this, IncludeEndDate);
    }

    // --- Date in Period ---

    static bool IsDateInPeriod(const clsPeriod& Period, const clsDate& Date)
    {
        return !(clsDate::CompareDates(Date, Period._StartDate) == clsDate::enCompareDates::Before ||
                clsDate::CompareDates(Date, Period._EndDate)   == clsDate::enCompareDates::After);
    }

    bool IsDateInPeriod(const clsDate& Date) const
    {
        return IsDateInPeriod(*this, Date);
    }

    // --- Overlap Days Count ---

    static short GetOverlapDays(const clsPeriod& Period1, const clsPeriod& Period2, bool IncludeEndDate = false)
    {
        if (IsOverlapPeriods(Period1, Period2))
        {
            clsDate OverlapStart = clsDate::IsDate1BeforeDate2(Period2._StartDate, Period1._StartDate) ? Period1._StartDate : Period2._StartDate;
            clsDate OverlapEnd   = clsDate::IsDate1BeforeDate2(Period1._EndDate, Period2._EndDate)     ? Period1._EndDate   : Period2._EndDate;

            return clsDate::GetDifferenceInDays(OverlapStart, OverlapEnd, IncludeEndDate);
        }

        return 0;
    }

    short GetOverlapDays(const clsPeriod& Period2, bool IncludeEndDate = false) const
    {
        return GetOverlapDays(*this, Period2, IncludeEndDate);
    }

    // --- UI / Print ---

    void Print() const
    {
        cout << "Period Start: ";
        _StartDate.Print();
        cout << "\nPeriod End  : ";
        _EndDate.Print();
        cout << endl;
    }
};