#include <iostream>
using namespace std;
int main()
{
    for (int x = 1; x <= 10; x++)
    {
        cout << "i = " << x << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << x << " * " << i << " = " << x * i << endl;
        }
        cout << "---------------------------\n";
    }
    return 0;
}