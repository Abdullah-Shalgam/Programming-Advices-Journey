#include <iostream>
#include <cstdlib>
using namespace std;
void ReadNumberAndVerify(int &Number)
{
    cout << "Please enter the number you want it Factorial : \n";
    cin >> Number;
    if (Number < 0)
    {
        cout << "You have entered a negative number; it will be converted to a positive number and the process will be completed.\n";
    }
}
int FactorialValue(int Num)
{
    int FactorialV = 1;
    for (int i = 1; i <= Num; i++)
    {
        FactorialV = FactorialV * i;
    }
    return FactorialV;
}
int main()
{
    int Number;
    ReadNumberAndVerify(Number);
    cout << "The FactorialValue of " << Number << " is : " << FactorialValue(Number);
    return 0;
}