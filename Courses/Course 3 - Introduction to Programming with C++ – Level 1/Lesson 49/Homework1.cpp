#include <iostream>
using namespace std;
int main()
{
    for (int i = 65; i <= 90; i++)
    {
        for (int x = 65; x <= 90; x++)
        {
            cout << char(i) << char(x) << endl;
        }
    }
    return 0;
}