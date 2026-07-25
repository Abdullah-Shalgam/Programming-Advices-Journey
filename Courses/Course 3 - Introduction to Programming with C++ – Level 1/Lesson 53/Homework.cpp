#include <iostream>
using namespace std;
int main()
{
    int Num , Sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter a Number : \n";
        cin >> Num;
        if (Num > 50)
        {
            continue;
        }
        Sum += Num;
    }
    cout << "\nThe Sum of Numbers is : " << Sum;
    return 0;
}