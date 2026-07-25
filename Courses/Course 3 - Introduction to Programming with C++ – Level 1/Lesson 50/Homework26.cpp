#include <iostream>
using namespace std;
int main()
{
    int EndNumber;
    int i = 1;
    cout << "Please enter the end number of the list : \n";
    cin >> EndNumber;
    while (EndNumber >= i)
    {
        cout << i << endl;
        i++;
    }
    return 0;
}