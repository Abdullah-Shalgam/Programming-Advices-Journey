#include <iostream>
using namespace std;

enum enYearMonths 
{
    January = 1, 
    February = 2, 
    March = 3, 
    April = 4, 
    May = 5, 
    June = 6, 
    July = 7, 
    August = 8, 
    September = 9, 
    October = 10, 
    November = 11, 
    December = 12
};

int ReadNumberInRange(int From, int To, string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= From && Num <= To)
            return Num;
        cout << "Invalid Input!\n";
    } while (true);
}

enYearMonths CheckYearMonths(int MonthNumber)
{
    return (enYearMonths) MonthNumber;
}

string GetMonthName(enYearMonths Month)
{
    switch (Month)
    {
    case enYearMonths::January:
        return "January";
    case enYearMonths::February:
        return "February";
    case enYearMonths::March:
        return "March";
    case enYearMonths::April:
        return "April";
    case enYearMonths::May:
        return "May";
    case enYearMonths::June:
        return "June";
    case enYearMonths::July:
        return "July";
    case enYearMonths::August:
        return "August";
    case enYearMonths::September:
        return "September";
    case enYearMonths::October:
        return "October";
    case enYearMonths::November:
        return "November";
    case enYearMonths::December:
        return "December";
    default:
        return "Invalid Month";
    }
}

void PrintMonth(string MonthName)
{
    cout << "\nit is " << MonthName;
}

int main()
{
    int MonthNumber = ReadNumberInRange(1, 12, "Please enter month number between 1 and 12 (January = 1, December = 12): ");
    PrintMonth(GetMonthName(CheckYearMonths(MonthNumber)));
    return 0;
}