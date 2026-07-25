#include <iostream>

using namespace std;

void PrintNumbersFromMtoN(int N, int M)
{
    if (N <= M)
    {
        cout << N << endl;
        PrintNumbersFromMtoN(N + 1, M);
    }
}

int main()
{
    PrintNumbersFromMtoN(1, 10);
    return 0;
}