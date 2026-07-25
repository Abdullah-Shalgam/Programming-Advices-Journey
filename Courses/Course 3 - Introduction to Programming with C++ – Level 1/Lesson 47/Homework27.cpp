#include <iostream>
using namespace std;
int main()
{
    int EndNumber;
    cout << "Please enter the end number of the list : \n";
    cin >> EndNumber;
    for (int i = EndNumber; i >= 1; i--)
    {
        cout << i << endl;
    }
    return 0;
}