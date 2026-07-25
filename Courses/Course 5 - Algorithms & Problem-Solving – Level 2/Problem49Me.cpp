#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Msg)
{
    float Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

float GetFractionPart(float Num)
{
    int IntegerPart = (int)Num;
    return Num - IntegerPart;
}

int MyCeil(float Num)
{
    if (Num <= 0 || GetFractionPart(Num) == 0)
        return (int)Num;
    else
        return (int)Num + 1;
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy Ceil Result: " << MyCeil(Num);
    cout << "\nC++ Result: " << ceil(Num);
    return 0;
}