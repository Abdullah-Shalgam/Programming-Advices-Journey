#include <iostream>
#include <cmath>
using namespace std;

float ReadDiameter()
{
    float Diameter;
    cout << "Please enter the diameter: ";
    cin >> Diameter;
    return Diameter;
}

float CircleAreaByDiameter(float Diameter)
{
    const float PI = 3.141592653589793238462643383279;
    return (PI * pow(Diameter, 2)) / 4;
}

void PrintCircleArea(float Area)
{
    cout << "\nCircle Area = " << Area;
}
int main()
{
    PrintCircleArea(CircleAreaByDiameter(ReadDiameter()));
    return 0;
}