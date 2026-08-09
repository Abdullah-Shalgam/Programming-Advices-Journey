#pragma once

#include <iostream>
#include "DateLib.h"

using namespace std;

class PeriodLib
{
private:
    DateLib _StartDate;
    DateLib _EndDate;

public:
    // Constructor
    PeriodLib(const DateLib& StartDate, const DateLib& DateTo);

    // Setters
    void SetStartDate(const DateLib& Date);
    void SetEndDate(const DateLib& Date);

    // Getters
    DateLib StartDate() const;
    DateLib EndDate() const;

    // Overlap Operations
    static bool IsOverlapPeriods(const PeriodLib& Period1, const PeriodLib& Period2);
    bool IsOverLapWith(const PeriodLib& Period2) const;

    // Period Length
    static int GetPeriodLengthInDays(const PeriodLib& Period, bool IncludeEndDate = false);
    int GetPeriodLengthInDays(bool IncludeEndDate = false) const;

    // Date in Period
    static bool IsDateInPeriod(const PeriodLib& Period, const DateLib& Date);
    bool IsDateInPeriod(const DateLib& Date) const;

    // Overlap Days Count
    static short GetOverlapDays(const PeriodLib& Period1, const PeriodLib& Period2, bool IncludeEndDate = false);
    short GetOverlapDays(const PeriodLib& Period2, bool IncludeEndDate = false) const;

    // UI / Print
    void Print() const;
};