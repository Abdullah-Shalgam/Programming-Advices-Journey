#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter a Number : \n";
    cin >> x;
    if (x > 5)
    {
        cout << "\nThe Number That You Entered More Than 5";
    }
    else
    {
        cout << "\nThe Number That You Entered Less Than 5";
    }
    return 0;
}