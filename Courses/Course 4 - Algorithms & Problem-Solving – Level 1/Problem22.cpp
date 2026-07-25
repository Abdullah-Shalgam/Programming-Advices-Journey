#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float &a, float &b)
{
    cout << "Please Enter a: ";
    cin >> a;
    cout << "Please Enter b: ";
    cin >> b;
}

float CircleAreaByInscribedInIsoscelesTriangle(float a, float b)
{
    const float PI = 3.141592653589793238462643383279;
    return PI * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
}

void PrintCircleArea(float Area)
{
    cout << "\nCircle Area = " << Area;
}
int main()
{
    float A , B;
    ReadNumbers(A, B);
    PrintCircleArea(CircleAreaByInscribedInIsoscelesTriangle(A, B));
    return 0;
}