#include <iostream>
using namespace std;
void MySumProcedure()
{
    int Num1 , Num2;
    cout << "Please enter Number 1:" << endl , cin >> Num1;
    cout << "Please enter Number 2:" << endl , cin >> Num2;
    cout << "********************************************" << endl;
    cout << Num1+Num2;
}
int main()
{
    MySumProcedure();
}