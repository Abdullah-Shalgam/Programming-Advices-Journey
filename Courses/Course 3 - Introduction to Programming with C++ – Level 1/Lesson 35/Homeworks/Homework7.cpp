#include <iostream>
#include <cmath>
using namespace std;
float CircleAreaInscribedInSquare(float A)
{
    const float Pi = 3.14;
    float Area = Pi*pow(A, 2)/4;
    return Area;
}
int main()
{
    float A;
    cout << "Please enter the A: " << endl , cin >> A;
    cout << "The Area = " << CircleAreaInscribedInSquare(A);
}