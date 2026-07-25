#include <iostream>
#include <cmath>
using namespace std;
float RectangleAreaThroughDiagonalAndSideArea(float a , float d)
{
    float Area = a * (sqrt(pow(d , 2) - pow(a , 2)));
    return Area;
}
int main()
{
    float a , d;
    cout << "Please enter the number of a: " << endl , cin >> a;
    cout << "Please enter the number of d: " <<endl , cin >> d;
    cout << "The Area = " << RectangleAreaThroughDiagonalAndSideArea(a , d);
}