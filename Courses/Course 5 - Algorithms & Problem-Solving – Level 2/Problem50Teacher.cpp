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

float MySqrt(float Num)
{
    if (Num > 0)
    {
       return pow(Num, 0.5);
    }
    else if (Num == 0)
        return 0;
    else
        return NAN;
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy Sqrt Result: " << MySqrt(Num);
    cout << "\nC++ Result: " << sqrt(Num);
    return 0;
}