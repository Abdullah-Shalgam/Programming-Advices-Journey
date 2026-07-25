#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float Pi = 3.14;
float A , B;
cout << "Please enter the A: " << endl , cin >> A;
cout << "Please enter the B: " << endl , cin >> B;
float Area = Pi*(pow(B, 2)/4)*((2*A-B)/(2*A+B));
cout << endl << endl << Area << endl << floor(Area);
return 0;
}