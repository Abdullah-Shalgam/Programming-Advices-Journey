#include <iostream>
using namespace std;
int main()
{
    int EndNumber;
    cout << "Please enter the end number of the list : \n";
    cin >> EndNumber;
    while (EndNumber >= 1)
    {
        cout << EndNumber << endl;
        EndNumber--;
    }
    return 0;
}