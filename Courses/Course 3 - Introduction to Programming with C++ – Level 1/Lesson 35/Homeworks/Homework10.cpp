#include <iostream>
#include <cmath>
using namespace std;
float CircleAreaCircleDescribedAroundArbitraryTriangle(float a , float b , float c)
{
    const float pi = 3.14;
    float p = (a+b+c)/2;
    float Area = pi * pow((a*b*c)/(4*(sqrt(p*(p-a)*(p-b)*(p-c)))) , 2);
    return Area;
}
int main()
{
    float a , b , c;
    cout << "Please enter the number of a: " << endl , cin >> a;
    cout << "Please enter the number of b: " << endl , cin >> b;
    cout << "Please enter the number of c: " << endl , cin >> c;
    cout << "The Area = " << CircleAreaCircleDescribedAroundArbitraryTriangle(a , b , c);
}