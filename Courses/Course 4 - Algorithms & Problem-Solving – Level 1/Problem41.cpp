#include <iostream>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    float Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input!";
    } while (true);
}

float CalculateWeeks(float Hours)
{
    return Hours / 168;
}

float CalculateDays(float Hours)
{
    return Hours / 24;
}

void PrintResult(float Hours)
{
    cout << "\nTotal Hours = " << Hours;
    cout << "\nTotal Weeks = " << CalculateWeeks(Hours);
    cout << "\nTotal Days = " << CalculateDays(Hours);
}

int main()
{
    float NumberofHours = ReadPositiveNumber("Please enter the number of hours: ");
    PrintResult(NumberofHours);
    return 0;
}