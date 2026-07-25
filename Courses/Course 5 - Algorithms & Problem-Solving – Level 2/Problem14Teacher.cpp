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

void PrintInvertedLetterPattern(int Num)
{
    cout << "\n";
    for (int i = Num + 64; i >= 65; i--)
    {
        for (int j = 1; j <= i - 64; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a number : "));
    return 0;
}