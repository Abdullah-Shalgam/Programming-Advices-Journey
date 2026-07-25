#include <iostream>
#include <cmath>
using namespace std;
float CircleAreaThroughDiameter(float D)
{
    const float Pi = 3.14;
    float Area = (Pi*pow(D , 2))/4;
    return Area;
}
int main()
{
    float D;
    cout << "Please enter the Diameter: " << endl , cin >> D;
    cout << "The Area = " << CircleAreaThroughDiameter(D);
}