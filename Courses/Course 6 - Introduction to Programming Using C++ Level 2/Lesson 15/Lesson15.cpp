#include <iostream>

using namespace std;

int MySum(int,int,int = 0,int = 0);

int main()
{
    cout << MySum(10, 20) << endl;
    cout << MySum(10, 20, 30) << endl;
    cout << MySum(10, 20, 30, 40);
    return 0;
}

int MySum(int a, int b, int c, int d)
{
    return a + b + c + d;
}