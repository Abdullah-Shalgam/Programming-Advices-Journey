#include <iostream>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

int ReadNumber(string Msg)
{
    int Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

enPrimeNotPrime CheckPrime(int Num)
{
    if(Num <= 1)
        return enPrimeNotPrime::NotPrime;
    for (int i = 2; i * i <= Num; i++)
    {
        if (Num % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void PrintIsPrime(int Num)
{
    switch (CheckPrime(Num))
    {
    case enPrimeNotPrime::Prime:
        cout << "\n" << Num << " is a prime number";
        break;
    default:
        cout << "\n" << Num << " is not a prime number";
        break;
    }
}
int main()
{
    PrintIsPrime(ReadNumber("Please enter a number: "));
    return 0;
}