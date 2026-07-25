#include <iostream>
using namespace std;

void ReadLengthWidth(float &L, float &W)
{
    cout << "Please Enter the Length: ";
    cin >> L;
    cout << "Please Enter the Width: ";
    cin >> W;
}

float CalculateArea(float L, float W)
{
    return L * W;
}

void PrintArea(float Area)
{
    cout << "\nRectangle Area = " << Area;
}

int main()
{
    float Length , Width;
    ReadLengthWidth(Length, Width);
    PrintArea(CalculateArea(Length, Width));
    return 0;
}