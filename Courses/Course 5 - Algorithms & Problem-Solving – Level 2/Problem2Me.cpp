#include <iostream>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input, Try agian.\n";
    } while (true);
}

enPrimeNotPrime CheckPrime(int i)
{
    if (i <= 1)
        return enPrimeNotPrime::NotPrime;
    for (int j = 2; j * j <= i; j++)
    {
        if (i % j == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

int ReturnPrimeNumber(int i)
{
    if (CheckPrime(i) == enPrimeNotPrime::Prime)
        return i;
    else
        return 0;
}

void PrintPrimeNumbersFrom1ToN(int EndNum)
{
    int PrimeNumber;
    cout << "All prime numbers form 1 to " << EndNum << " : ";
    for (int i = 1; i <= EndNum; i++)
    {
        PrimeNumber = ReturnPrimeNumber(i);
        if (PrimeNumber != 0)
        {
            cout << endl << PrimeNumber;
        }
    }
}
int main()
{
    int EndOfNumbers = ReadPositiveNumber("Please enter the last number you want to check is prime or not: ");
    PrintPrimeNumbersFrom1ToN(EndOfNumbers);
    return 0;
}