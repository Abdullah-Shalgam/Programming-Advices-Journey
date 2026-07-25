#include <iostream>
using namespace std;

enum enOddorEven {Odd = 1, Even = 2};

int ReadNumber()
{
    int N;
    cout << "Please Enter the end of Numbers: ";
    cin >> N;
    return N;
}

enOddorEven CheckOddorEven(int N)
{
    if (N % 2 == 0)
        return enOddorEven::Even;
    else
        return enOddorEven::Odd;
}

int OddSumFrom1toN(int N)
{
    int Sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (CheckOddorEven(i) == enOddorEven::Odd)
        {
            Sum += i;
        }
    }
    return Sum;
}

int main()
{
    int N = ReadNumber();
    cout << "Odd Sum From N to 1 = " << OddSumFrom1toN(N);
    return 0;
}