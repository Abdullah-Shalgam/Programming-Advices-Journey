#include <iostream>
#include <cmath>
using namespace std;

float ReadRadius()
{
    float Radius;
    cout << "Please enter the radius r: ";
    cin >> Radius;
    return Radius;
}

float CircleArea(float Radius)
{
    const float PI = 3.141592653589793238462643383279;
    return PI * pow(Radius, 2);
}

void PrintCircleArea(float Area)
{
    cout << "\n Circle Area = " << Area;
}
int main()
{
    PrintCircleArea(CircleArea(ReadRadius()));
    return 0;
}