#include <iostream>
using namespace std;
int main()
{
    for (int i = 65; i <= 90; i++)
    {
        for (int x = 65; x <= i; x++)
        {
            cout << char(x);
        }
        cout << "\n";
    }
    return 0;
}