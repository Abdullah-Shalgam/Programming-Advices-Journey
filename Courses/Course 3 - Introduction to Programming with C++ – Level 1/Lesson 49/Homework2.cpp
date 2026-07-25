#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i >= 1; i--)
    {
        for (int x = 1; x <= i; x++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}