#include <iostream>
using namespace std;
int main()
{
    int time;
    cout << "Please Enter the time : \n";
    cin >> time;
    if (time < 10)
    {
        cout << "\nGood Morning";
    }
    else if (time < 20)
    {
        cout << "\nGood Day";
    }
    else
    {
        cout << "\nGood Evening";
    }
    return 0;
}