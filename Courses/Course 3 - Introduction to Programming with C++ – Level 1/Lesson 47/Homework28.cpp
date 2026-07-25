#include <iostream>
using namespace std;
int main()
{
    int LastNumber;
    int SumofNumbers = 0;
    cout << "Please enter the last number of the sum opration : \n";
    cin >> LastNumber;
    for (int i = 1; i <= LastNumber; i = i + 2)
    {
        SumofNumbers = SumofNumbers + i;
    }
    cout << SumofNumbers;
    return 0;
}