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

int MyFloor(float Num)
{
    if (Num >= 0 || GetFractionPart(Num) == 0)
        return (int)Num;
    else
        return (int)Num - 1;
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy Floor Result: " << MyFloor(Num);
    cout << "\nC++ Result: " << floor(Num);
    return 0;
}