#include <iostream>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num > 0)
            return Num;
        cout << "Invalid Input, Try again.\n";
    } while (true);
}

bool isPerfectNumber(int Num)
{
    if (Num == 1)
        return false;
    int Sum = 1;
    int Root = sqrt(Num); 
    for (int i = 2; i <= Root; i++)
    {
        if (Num % i == 0)
        {
            Sum += i;
            if (i != (Num / i))
                Sum += (Num / i);
        }
    }
    return Sum == Num;
}

void PrintPerfectNumbersFrom1ToN(int EndNum)
{
    cout << "All Perfect Numbers From 1 to " << EndNum << " is: ";
    for (int i = 1; i <= EndNum; i++)
    {
        if (isPerfectNumber(i))
            cout << endl << i;
    }
}

int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter the last number you want to check Perfect or Not: "));
    return 0;
}