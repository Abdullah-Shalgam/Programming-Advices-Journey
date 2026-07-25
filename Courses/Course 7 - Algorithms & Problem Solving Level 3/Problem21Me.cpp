#include <iostream>
#include "InputLib.h"

using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
    int Prev2 = 1, Prev1 = 0, NextFibonacciNumber = 1;
    cout << "\nFirst "<< Number << " Fibonacci Numbers is:\n\n";
    for (short i = 1; i <= Number; i++)
    {
        NextFibonacciNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = NextFibonacciNumber;
        cout << NextFibonacciNumber << "   ";
    }
}

int main()
{
    PrintFibonacciUsingLoop(InputLib::ReadIntNumber("Please enter the end of fibonacci: "));
    return 0;
}