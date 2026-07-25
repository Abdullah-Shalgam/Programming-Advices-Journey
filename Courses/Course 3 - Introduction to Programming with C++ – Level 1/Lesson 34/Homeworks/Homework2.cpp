#include <iostream>
#include <cmath>
using namespace std;
float MySumFunction()
{
    float Num1 , Num2;
    cout << "Please enter Number 1:" << endl , cin >> Num1;
    cout << "Please enter Number 2:" << endl , cin >> Num2;
    cout << "********************************************" << endl;
    return Num1+Num2;
}
int main()
{
    cout << sqrt((MySumFunction() + 10));
}