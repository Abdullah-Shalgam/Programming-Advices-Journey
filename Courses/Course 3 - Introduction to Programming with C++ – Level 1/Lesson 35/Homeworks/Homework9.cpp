#include <iostream>
#include <cmath>
using namespace std;
float CircleAreaInscribedInIsoscelesTriangle(float A , float B)
{
    const float Pi = 3.14;
    float Area = Pi*(pow(B, 2)/4)*((2*A-B)/(2*A+B));
    return Area;
}
int main()
{
    float A , B;
    cout << "Please enter the A: " << endl , cin >> A;
    cout << "Please enter the B: " << endl , cin >> B;
    cout << "The Area = " << CircleAreaInscribedInIsoscelesTriangle(A , B);
}