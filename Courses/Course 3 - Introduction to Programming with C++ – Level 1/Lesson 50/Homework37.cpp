#include <iostream>
using namespace std;
int main()
{
    int Number;
    int Sum = 0;
    cout << "Enter a Number : \n";
    cin >> Number;
    while (Number != -99)
    {
        Sum = Sum + Number;
        cout << "Enter a Number : \n";
        cin >> Number;
    }
    cout << Sum;
    return 0;
}