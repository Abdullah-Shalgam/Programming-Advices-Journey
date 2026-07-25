#include <iostream>
#include <cmath>
using namespace std;
float RectangleArea(float Length , float Width)
{
    float Area = Length*Width;
    return Area;
}
int main()
{
    float Length , Width;
    cout << "Please enter the Length: " << endl , cin >> Length;
    cout << "Please enter the Width: " << endl , cin >> Width;
    cout << "The Area = " << RectangleArea(Length , Width);
}