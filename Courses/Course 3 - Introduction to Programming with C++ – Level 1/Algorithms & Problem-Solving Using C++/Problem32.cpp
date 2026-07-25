#include <iostream>
#include <cmath>
using namespace std;
int main()
{
float Num , Power;
cout << "Please enter a Number: " << endl , cin >> Num;
cout << "Please enter Power of Number: " << endl , cin >> Power;
float PowerOfNumber = pow(Num , Power);
cout << endl << endl << PowerOfNumber << endl << round(PowerOfNumber);
return 0;
}