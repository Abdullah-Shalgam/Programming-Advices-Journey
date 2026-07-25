#include <iostream>
#include <cmath>
using namespace std;

float ReadSideLength()
{
    float SideLength;
    cout << "Please enter the side length: ";
    cin >> SideLength;
    return SideLength;
}

float CircleAreaInscribedINSquare(float SideLength)
{
    const float PI = 3.141592653589793238462643383279;
    return (PI * pow(SideLength, 2)) / 4;
}

void PrintCircleArea(float Area)
{
    cout << "\nCircle Area = " << Area;
}
int main()
{
    PrintCircleArea(CircleAreaInscribedINSquare(ReadSideLength()));
    return 0;
}