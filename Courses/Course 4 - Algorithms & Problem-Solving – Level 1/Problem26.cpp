#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please Enter the end of Numbers: ";
    cin >> N;
    return N;
}

void PrintNumbersInRange_UsingFor(int N)
{
    cout << "1 to " << N << " = \n\n";
    for (int i = 1; i <= N; i++)
    {
        cout << i << endl;
    }
}

void PrintNumbersInRange_UsingWhile(int N)
{
    int i = 1;
    cout << "1 to " << N << " = \n\n";
    while (i <= N)
    {
        cout << i << endl;
        i++;
    }
}

void PrintNumbersInRange_UsingDoWhile(int N)
{
    int i = 1;
    cout << "1 to " << N << " = \n\n";
    do
    {
        cout << i << endl;
        i++;
    } while (i <= N);
}

int main()
{
    int N = ReadNumber();
    cout << endl;
    PrintNumbersInRange_UsingFor(N);
    cout << endl;
    PrintNumbersInRange_UsingWhile(N);
    cout << endl;
    PrintNumbersInRange_UsingDoWhile(N);
    return 0;
}