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

float MyAbs(float Num)
{
    if (Num >= 0)
        return Num;
    return Num * -1;
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy abs Result: " << MyAbs(Num);
    cout << "\nC++ Result: " << abs(Num);
    return 0;
}