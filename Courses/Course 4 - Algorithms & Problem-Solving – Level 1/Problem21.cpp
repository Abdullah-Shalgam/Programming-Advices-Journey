#include <iostream>
#include <cmath>
using namespace std;

float ReadCircleCircumference()
{
    int L;
    cout << "Please Enter Circle Circumference: ";
    cin >> L;
    return L;
}

float CircleAreaAlongTheCircumFerence(float L)
{
    const float PI = 3.141592653589793238462643383279;
    return pow(L, 2) / (4 * PI);
}

void PrintCircleArea(float Area)
{
    cout << "\nCircle Area = " << Area;
}
int main()
{
    PrintCircleArea(CircleAreaAlongTheCircumFerence(ReadCircleCircumference()));
    return 0;
}