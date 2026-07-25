#include <iostream>
using namespace std;

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
}

int CalculateDigitFrequency(int Num, short Digit)
{
    if (Num == 0)
        return (Digit == 0) ? 1 : 0;
    int Remainder = 0 , Frequency = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        if (Remainder == Digit)
            Frequency++;
    }
    return Frequency;
}

void PrintDigitFrequency(short Digit, int Frequency)
{
    cout << "\nDigit " << Digit << " Frequency " << Frequency << " Time(s).";
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a number : ");
    short Digit = ReadPositiveNumber("Please enter a Digit : ");
    int Frequency = CalculateDigitFrequency(Number, Digit);
    PrintDigitFrequency(Digit, Frequency);
    return 0;
}