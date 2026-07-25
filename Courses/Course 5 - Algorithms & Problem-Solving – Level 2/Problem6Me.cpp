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

int CalculateSumOfDigits(int Num)
{
    int Remainder = 0;
    int Sum = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        Sum += Remainder;
    }
    return Sum;
}

void PrintSumOfDigits(int Sum)
{
    cout << "\nSum of Digits = " << Sum;
}

int main()
{
    PrintSumOfDigits(CalculateSumOfDigits(ReadPositiveNumber("Please enter a number : ")));
    return 0;
}