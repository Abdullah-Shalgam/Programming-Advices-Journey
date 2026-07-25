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

int MyRound(float Num)
{
    float FractionOfNumber = GetFractionPart(Num);
    int IntegerPart = (int)Num;
    if (Num >= 0)
    {
        if (FractionOfNumber >= 0.5)
            return IntegerPart + 1;
        else
            return IntegerPart;
    }
    else
    {
        if (FractionOfNumber <= -0.5)
            return IntegerPart - 1;
        else
            return IntegerPart;
    }
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy Round Result: " << MyRound(Num);
    cout << "\nC++ Result: " << round(Num);
    return 0;
}