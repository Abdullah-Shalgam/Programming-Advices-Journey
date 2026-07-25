#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float Pi = 3.14;
float A;
cout << "Please enter the A: " << endl , cin >> A;
float Area = Pi*pow(A, 2)/4;
cout << endl << endl << Area << endl << ceil(Area);
return 0;
}