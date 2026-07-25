#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float pi = 3.14;
float a , b , c;
cout << "Please enter the number of a: " << endl , cin >> a;
cout << "Please enter the number of b: " << endl , cin >> b;
cout << "Please enter the number of c: " << endl , cin >> c;
float p = (a+b+c)/2;
float Area = pi * pow((a*b*c)/(4*(sqrt(p*(p-a)*(p-b)*(p-c)))) , 2);
cout << endl << endl << Area << endl << round(Area);
return 0;
}