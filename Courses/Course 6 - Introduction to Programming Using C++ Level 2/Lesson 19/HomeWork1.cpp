#include <iostream>

using namespace std;

void PrintNumbersFromMtoN(int M, int N)
{
    if (M >= N)
    {
        cout << M << endl;
        PrintNumbersFromMtoN(M - 1, N);
    }
}

int main()
{
    PrintNumbersFromMtoN(10, 1);
    return 0;
}