#include <iostream>

using namespace std;

int MyPow(int N, int M)
{
    if (M == 0)
        return 1;
    else
        return (N * MyPow(N, M - 1)) ;
}

int main()
{
    cout << MyPow(3, 4);
    return 0;
}