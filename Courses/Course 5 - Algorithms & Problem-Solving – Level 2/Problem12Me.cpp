#include <iostream>
using namespace std;

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
}

void PrintInvertedNumberPattern(int Num)
{
    cout << "\n";
    for (int i = Num; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

int main()
{
    PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a number : "));
    return 0;
}