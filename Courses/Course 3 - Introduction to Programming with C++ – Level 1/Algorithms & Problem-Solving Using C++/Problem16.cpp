#include <iostream>
#include <cmath>
using namespace std;
int main()
{
float a , d;
cout << "Please enter the number of a: " << endl , cin >> a;
cout << "Please enter the number of d: " <<endl , cin >> d;
float Area = a * (sqrt(pow(d , 2) - pow(a , 2)));
cout << endl << endl << Area;
return 0;
}