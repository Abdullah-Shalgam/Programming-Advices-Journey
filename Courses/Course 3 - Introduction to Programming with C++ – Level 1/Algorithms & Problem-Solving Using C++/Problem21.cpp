#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float Pi = 3.14;
float L;
cout << "Please enter the L: " << endl , cin >> L;
float Area = pow(L, 2)/(4*Pi);
cout << endl << endl << Area << endl << floor(Area);
return 0;    
}