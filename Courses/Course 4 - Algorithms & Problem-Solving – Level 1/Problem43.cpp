#include <iostream>
using namespace std;

struct stDuration
{
    int NumberofDays;
    int NumberofHours;
    int NumberofMinutes;
    int NumberofSeconds;
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

int ReadTotalSeconds()
{
    int TotalSeconds = ReadPositiveNumber("Please enter the total seconds: ");
    return TotalSeconds;
}

stDuration CalculateDuration(int TotalSeconds)
{
    stDuration Duration;
    const int SecondsInDay = 86400;
    const int SecondsInHour = 3600;
    const int SecondsInMinutes = 60;
    int Remainder = TotalSeconds;
    Duration.NumberofDays = Remainder / SecondsInDay;
    Remainder %= SecondsInDay;
    Duration.NumberofHours = Remainder / SecondsInHour;
    Remainder %= SecondsInHour;
    Duration.NumberofMinutes = Remainder / SecondsInMinutes;
    Remainder %= SecondsInMinutes;
    Duration.NumberofSeconds = Remainder;
    return Duration;
}

void PrintDuration(stDuration Duration)
{
    cout << "\nDays:Hours:Minutes:Seconds\n";
    cout << Duration.NumberofDays << ":" 
         << Duration.NumberofHours << ":" 
         << Duration.NumberofMinutes << ":" 
         << Duration.NumberofSeconds;
}

int main()
{
    int TotalSeconds = ReadTotalSeconds();
    stDuration Duration = CalculateDuration(TotalSeconds);
    PrintDuration(Duration);
    return 0;
}