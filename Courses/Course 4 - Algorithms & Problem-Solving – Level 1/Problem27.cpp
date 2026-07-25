#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please Enter the end of Numbers: ";
    cin >> N;
    return N;
}

void PrintNumbersFromNto1_UsingFor(int N)
{
    cout << N << " to 1 = \n\n";
    for (int i = 1; N >= i; N--)
    {
        cout << N << endl;
    }
}

void PrintNumbersFromNto1_UsingWhile(int N)
{
    int i = 1;
    cout << N << " to 1 = \n\n";
    while (N >= i)
    {
        cout << N << endl;
        N--;
    }
}

void PrintNumbersFromNto1_UsingDoWhile(int N)
{
    int i = 1;
    cout << N << " to 1 = \n\n";
    do
    {
        cout << N << endl;
        N--;
    } while (N >= i);
}

int main()
{
    int N = ReadNumber();
    cout << endl;
    PrintNumbersFromNto1_UsingFor(N);
    cout << endl;
    PrintNumbersFromNto1_UsingWhile(N);
    cout << endl;
    PrintNumbersFromNto1_UsingDoWhile(N);
    return 0;
}