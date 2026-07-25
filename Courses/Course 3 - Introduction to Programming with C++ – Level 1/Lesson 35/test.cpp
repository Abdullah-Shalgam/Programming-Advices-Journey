#include <iostream>
#include <cmath>
using namespace std;
float MySumFunction(float Num1 ,float Num2)
{
    return Num1+Num2;
}
int main()
{
    float Num1 , Num2;
    cin >> Num1 , cin >> Num2;
    cout << sqrt((MySumFunction(Num1 , Num2) + 10));
}