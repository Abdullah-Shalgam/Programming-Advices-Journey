#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float &a, float &b, float &c)
{
    cout << "Please Enter a: ";
    cin >> a;
    cout << "Please Enter b: ";
    cin >> b;
    cout << "Please Enter c: ";
    cin >> c;
}

float CalculateP(float a, float b, float c)
{
    return (a + b + c) / 2;
}

float CalculateCircleAreaByArbitraryTriangle(float a, float b, float c, float p)
{
    const float PI = 3.141592653589793238462643383279;
    return PI * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
}

void PrintCircleArea(float Area)
{
    cout << "\nCircle Area = " << Area;
}

int main()
{
    float A , B , C;
    ReadNumbers(A, B, C);
    PrintCircleArea(CalculateCircleAreaByArbitraryTriangle(A, B, C, CalculateP(A, B, C)));
    return 0;
}