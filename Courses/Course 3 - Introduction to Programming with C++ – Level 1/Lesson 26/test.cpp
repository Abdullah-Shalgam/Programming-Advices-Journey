#include <iostream>
#include <cmath>
using namespace std;
int main()
{
double x;
cout << "Please enter a Number: " << endl , cin >> x;
cout << sqrt(x) << endl;
cout << round(x) << endl;
cout << pow(x , 2) << endl;
cout << ceil(x) << endl;
cout << floor(x) << endl;
cout << abs(x);
return 0;
}