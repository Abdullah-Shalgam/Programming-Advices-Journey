#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float pi = 3.14;
float r;
cout << "Please enter the number of r: " << endl , cin >> r;
float Area = pi * pow(r , 2);
cout << endl << endl << Area << endl << ceil(Area);
return 0;
}