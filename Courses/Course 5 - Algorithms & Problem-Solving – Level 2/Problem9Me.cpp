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

void PrintAllDigitsFrequency(int Num)
{
    int DigitFrequency = 0;
    for (int i = 0; i <= 9; i++)
    {
        DigitFrequency = CalculateDigitFrequency(Num, i);
        if (DigitFrequency != 0)
            cout << "\nDigit " << i << " Frequency is " << DigitFrequency << " Time(s).";
    }
}

int main()
{
    PrintAllDigitsFrequency(ReadPositiveNumber("Please enter a number : "));
    return 0;
}