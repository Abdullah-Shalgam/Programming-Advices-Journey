#include <iostream>
using namespace std;

enum enWeekDays {Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7};

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

enWeekDays CheckWeekDay(int Num)
{
    return (enWeekDays) Num;
}

string GetDayName(enWeekDays WeekDays)
{
    switch (WeekDays)
    {
    case enWeekDays::Sunday:
        return "Sunday";
    case enWeekDays::Monday:
        return "Monday";
    case enWeekDays::Tuesday:
        return "Tuesday";
    case enWeekDays::Wednesday:
        return "Wednesday";
    case enWeekDays::Thursday:
        return "Thursday";
    case enWeekDays::Friday:
        return "Friday";
    case enWeekDays::Saturday:
        return "Saturday";
    default:
        return "";
    }
}

void PrintDay(string DayName)
{
    cout << "\nit is " << DayName;
}
int main()
{
    int DayNumber = ReadNumberInRange(1, 7, "Please enter day number between 1 and 7 (Sunday = 1, Saturday = 7): ");
    PrintDay(GetDayName(CheckWeekDay(DayNumber)));
    return 0;
}