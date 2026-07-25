#include <iostream>
using namespace std;
int main()
{
    int UserPin;
    cout << "Please Enter the ATM PIN code : \n";
    cin >> UserPin;
    if (UserPin == 1234)
    {
        cout << "Your Balance is : 7500";
    }
    else
    {
        cout << "Worng PIN code";
    }
    return 0;
}