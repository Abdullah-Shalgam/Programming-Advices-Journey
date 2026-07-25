#include <iostream>
using namespace std;
int main()
{
    int x[10] {10, 20, 44, 55, 33, 99, 22, 88, 99, 100};
    for (int i = 0; i <= 10; i++)
    {
        cout << "We are at ateration " << i+1 << endl;
        if (x[i] == 10)
        {
            cout << endl << 55 << " found at position " << i+1;
            break;
        }
    }
    return 0;
}