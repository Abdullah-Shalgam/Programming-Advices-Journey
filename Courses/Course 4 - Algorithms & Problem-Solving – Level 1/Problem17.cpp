#include <iostream>
using namespace std;

void ReadNumbers(float &Base , float &Height)
{
    cout << "Please enter the base length a: ";
    cin >> Base;
    cout <<"Please enter the height h: ";
    cin >> Height;
}

float TriangleArea(float Base , float Height)
{
    return (Base/2) * Height;
}

void PrintArea(float Area)
{
    cout << "\nTriangleArea = " << Area;
}
int main()
{
    float Base , Height;
    ReadNumbers(Base,Height);
    PrintArea(TriangleArea(Base,Height));
    return 0;
}