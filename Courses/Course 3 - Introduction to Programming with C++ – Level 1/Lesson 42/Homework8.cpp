#include <iostream>
using namespace std;
int main()
{
    float Mark;
    cout << "Please Enter Your Mark : \n";
    cin >> Mark;
    if (Mark >= 50)
    {
        cout << "\nCongratulations, you have passed";
    }
    else
    {
        cout << "\nSorry, but you failed";
    }
    return 0;
}