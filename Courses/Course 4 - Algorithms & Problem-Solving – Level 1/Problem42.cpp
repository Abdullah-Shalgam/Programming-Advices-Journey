#include <iostream>
using namespace std;

struct stDuration
{
    int Days;
    int Hours;
    int Minutes;
    int Seconds;
};

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input!";
    } while (true);
}

stDuration ReadDuration()
{
    stDuration Duration;
    Duration.Days    = ReadPositiveNumber("Please enter number of days: ");
    Duration.Hours   = ReadPositiveNumber("Please enter number of hours: ");
    Duration.Minutes = ReadPositiveNumber("Please enter number of minutes: ");
    Duration.Seconds = ReadPositiveNumber("Please enter number of seconds: ");
    return Duration;
}

int CalculateTotalSeconds(stDuration Duration)
{
    const int SecondsInDay = 86400;
    const int SecondsInHour = 3600;
    const int SecondsInMinutes = 60;
    return Duration.Seconds + (Duration.Minutes * SecondsInMinutes) + (Duration.Hours * SecondsInHour) + (Duration.Days * SecondsInDay);
}

void PrintTotalSeconds(int TotalSeconds)
{
    cout << "\nTotal Seconds = " << TotalSeconds;
}

int main()
{
    stDuration Duration = ReadDuration();
    int TotalSeconds = CalculateTotalSeconds(Duration);
    PrintTotalSeconds(TotalSeconds);
    return 0;
}