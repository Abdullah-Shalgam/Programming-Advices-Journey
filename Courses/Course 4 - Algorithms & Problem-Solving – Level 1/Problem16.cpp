#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float &a , float &d)
{
    cout << "Please enter rectangle side A: ";
    cin >> a;
    cout << "Please enter rectangle diagonal D: ";
    cin >> d;
}

float RectangleAreaBySideAndDiagonal(float a , float d)
{
    return a * (sqrt(pow(d, 2) - pow(a, 2)));
}

void PrintArea(float Area)
{
    cout << "\nRectangle Area = " << Area;
}
int main()
{
    float A , D;
    ReadNumbers(A,D);
    PrintArea(RectangleAreaBySideAndDiagonal(A,D));
    return 0;
}