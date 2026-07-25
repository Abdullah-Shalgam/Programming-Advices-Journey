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

void PrintLetterPattern(int Num)
{
    cout << "\n";
    for (int i = 1; i <= Num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(i + 64);
        }
        cout << "\n";
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please enter a number : "));
    return 0;
}