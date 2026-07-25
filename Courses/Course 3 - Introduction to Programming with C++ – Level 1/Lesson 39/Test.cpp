#include <iostream>
using namespace std;
int main()
{
    int x[5] = {22, 43, 483, 34, 2929};
    cout << x[0] << endl;
    cout << x[1] << endl;
    cout << x[2] << endl;
    cout << x[3] << endl;
    cout << x[4] << endl;
    cout << x[3] + x[1];
    cout << "\nPlease Enter a Number : " , cin >> x[4] , cout << x[4];
    return 0;
}