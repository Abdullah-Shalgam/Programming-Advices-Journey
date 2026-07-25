#include <iostream>
#include <cmath>
using namespace std;
int main()
{
float Num;
cout << "Please enter a Number: " << endl , cin >> Num;
cout << endl << endl << Num*Num << endl << Num*Num*Num << endl << Num*Num*Num*Num;
cout << endl << round(Num*Num) << endl << round(Num*Num*Num) << endl << round(Num*Num*Num*Num);
return 0;
}