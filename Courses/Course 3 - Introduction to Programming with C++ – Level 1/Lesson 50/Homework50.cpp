#include <iostream>
using namespace std;
int main()
{
    int PIN;
    cout << "Enter the PIN CODE : \n";
    cin >> PIN;
    int i = 2;
    while (PIN != 1234 && i != 0)
    {
        cout << "You Entered a Wrong Number Enter it again : \n";
        cin >> PIN;
        i--;
    }
    if (i == 0)
    {
        cout << "Card is Locked";
    }
    else if (PIN == 1234)
    {
        cout << "Your Balance is: 7500";
    }
    return 0;
}