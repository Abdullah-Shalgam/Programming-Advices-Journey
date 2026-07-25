#include <iostream>
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
        cout << "Invalid Input, Try agian.\n";
    } while (true);
}

bool isPerfectNumber(int Num)
{
    int Sum = 1;
    for (int i = 2; i <= Num / 2; i++)
    {
        if (Num % i == 0)
            Sum += i;
    }
    return Sum == Num;
}

void PrintPerfectNotPerfectNumber(int Num)
{
    cout << endl;
    if (isPerfectNumber(Num))
        cout <<  Num << " is Perfect Number.";
    else 
        cout << Num << " is Not Perfect Number." ;
}
int main()
{
    PrintPerfectNotPerfectNumber(ReadPositiveNumber("Please enter a number to check perfect or not: "));
    return 0;
}