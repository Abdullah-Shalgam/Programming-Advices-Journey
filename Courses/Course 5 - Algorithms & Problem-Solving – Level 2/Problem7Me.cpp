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

int NumberLength(int Num)
{
    int i = 10;
    while (true)
    {
        if (Num / i == 0)
            return i;
        i *= 10;
    }
}

int ReversedNumber(int Num)
{
    int Remainder = 0;
    int ReversedNumber = 0;
    int Counter = NumberLength(Num);
    while (Num > 0)
    {
        Counter /= 10;
        Remainder = Num % 10;
        Num /= 10;
        ReversedNumber += Remainder * Counter;
    }
    return ReversedNumber;
}

void PrintReversedNumber(int ReversedNumber)
{
    cout << "\nReversed Number = " << ReversedNumber;
}

int main()
{
    PrintReversedNumber(ReversedNumber(ReadPositiveNumber("Please enter a number : ")));
    return 0;
}