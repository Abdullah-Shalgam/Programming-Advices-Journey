#include <iostream>
using namespace std;
int main()
{
    int LastNumber;
    int SumofNumbers = 0;
    int i = 0;
    cout << "Please enter the last number of the sum opration : \n";
    cin >> LastNumber;
    while (LastNumber >= i)
    {
        SumofNumbers = SumofNumbers + i;
        i = i + 2;
    }
    cout << SumofNumbers;
    return 0;
}