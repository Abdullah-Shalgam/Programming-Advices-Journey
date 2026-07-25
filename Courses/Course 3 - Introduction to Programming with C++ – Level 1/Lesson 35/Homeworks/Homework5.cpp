#include <iostream>
#include <cmath>
using namespace std;
float CircleArea(float r)
{
    const float pi = 3.14;
    float Area = pi * pow(r , 2);
    return Area;
}
int main()
{
    float r;
    cout << "Please enter the number of r: " << endl , cin >> r;
    cout << "The Area = " << CircleArea(r);
}