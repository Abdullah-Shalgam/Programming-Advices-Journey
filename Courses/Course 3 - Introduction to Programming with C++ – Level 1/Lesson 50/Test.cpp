#include <iostream>
using namespace std;

int NumberInRange(int start , int end)
{
    int Number;
    cout << "Please Enter a Number between " << start << " and " << end << " : \n";
    cin >> Number;
    while (Number < start || Number > end)
    {
        cout << "Wrong Number, Please Enter a Number Between " << start << " and " << end << " : \n";
        cin >> Number;
    }
    return Number;
}

int main()
{
    int Number = NumberInRange(1,100);
    cout << "\nThe Number is : " << Number;
    return 0;
}