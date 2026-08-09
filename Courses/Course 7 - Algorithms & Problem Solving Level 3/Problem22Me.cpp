#include <iostream>
#include "InputValidateLib.h"

using namespace std;

void PrintFibonacciUsingRecurssion(int Number, int Prev2 = 1, int Prev1 = 0)
{
    int NextFibonacciNumber = 0;
    if (Number != 0)
    {
        NextFibonacciNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = NextFibonacciNumber;
        cout << NextFibonacciNumber << "   ";
        PrintFibonacciUsingRecurssion(Number - 1, Prev2, Prev1);
    }
}

int main()
{
    int Number = InputValidateLib::ReadIntNumber("Please enter the end of fibonacci: ");
    cout << "\nFirst "<< Number << " Fibonacci Numbers is:\n\n";
    PrintFibonacciUsingRecurssion(Number, 1, 0);
    return 0;
}