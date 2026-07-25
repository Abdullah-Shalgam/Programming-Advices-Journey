#include <iostream>
using namespace std;

void ReadNumberAndVerify(int &Number)
{
    cout << "Please enter the number you want it Factorial : \n";
    cin >> Number;
    while (Number < 0)
    {
        cout << "Wrong Number, You have entered a negative number Try to Enter again : \n";
        cin >> Number;
    }
}

int FactorialValue(int Num)
{
    int FactorialV = 1;
    int i = 1;
    while (Num >= i)
    {
        FactorialV = FactorialV * i;
        i++;
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