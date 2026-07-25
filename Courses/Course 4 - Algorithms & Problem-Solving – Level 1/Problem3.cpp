#include <iostream>
using namespace std;

enum enNumberType {Odd = 1, Even = 2};

int ReadNumber()
{
    int Num;
    cout << "Please Enter a Number : ";
    cin >> Num;
    return Num;
}

enNumberType CheckNumberType(int Num)
{
    if (Num % 2 == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}

void PrintNumberType(enNumberType NumType)
{
    if (NumType == enNumberType::Even)
        cout << "Your Entered a Even Number";
    else
        cout << "Your Entered a Odd Number";
}
int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}