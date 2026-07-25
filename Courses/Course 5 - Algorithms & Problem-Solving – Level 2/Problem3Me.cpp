#include <iostream>
using namespace std;

enum enPerfectNotPerfect {Perfect = 1, NotPerfect = 2};

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

enPerfectNotPerfect CheckPerfectNumber(int Num)
{
    int Sum = 1;
    for (int i = 2; i <= Num / 2; i++)
    {
        if (Num % i == 0)
            Sum += i;
    }
    if (Sum == Num)
        return enPerfectNotPerfect::Perfect;
    else
        return enPerfectNotPerfect::NotPerfect;
}

void PrintPerfectNotPerfectNumber(int Num)
{
    cout << endl;
    if (CheckPerfectNumber(Num) == enPerfectNotPerfect::Perfect)
        cout <<  Num << " is Perfect Number.";
    else 
        cout << Num << " is Not Perfect Number." ;
}
int main()
{
    PrintPerfectNotPerfectNumber(ReadPositiveNumber("Please enter a number to check perfect or not: "));
    return 0;
}