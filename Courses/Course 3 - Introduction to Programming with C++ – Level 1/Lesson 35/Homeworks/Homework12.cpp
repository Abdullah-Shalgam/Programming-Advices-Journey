#include <iostream>
#include <cmath>
using namespace std;
float PowerOf_M(float Num , float Power)
{
    float PowerOfNumber = pow(Num , Power);
    return PowerOfNumber;
}
int main()
{
    float Num , Power;
    cout << "Please enter a Number: " << endl , cin >> Num;
    cout << "Please enter Power of Number: " << endl , cin >> Power;
    cout << Num << " Power " << Power << " = " << PowerOf_M(Num,Power);
}