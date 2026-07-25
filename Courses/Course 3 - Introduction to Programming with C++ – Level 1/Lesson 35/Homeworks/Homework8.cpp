#include <iostream>
#include <cmath>
using namespace std;
float CircleAreaAlongTheCircumference(float L)
{
    const float Pi = 3.14;
    float Area = pow(L, 2)/(4*Pi);
    return Area;
}
int main()
{
    float L;
    cout << "Please enter the L: " << endl , cin >> L;
    cout << "The Area = " << CircleAreaAlongTheCircumference(L);
}