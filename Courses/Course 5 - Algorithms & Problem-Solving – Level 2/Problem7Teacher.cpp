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

int ReversedNumber(int Num)
{
    int Remainder = 0 , Reversed = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        Reversed = Reversed * 10 + Remainder;
    }
    return Reversed;
}

void PrintReversedNumber(int Sum)
{
    cout << "\nSum of Digits = " << Sum;
}

int main()
{
    PrintReversedNumber(ReversedNumber(ReadPositiveNumber("Please enter a number : ")));
    return 0;
}