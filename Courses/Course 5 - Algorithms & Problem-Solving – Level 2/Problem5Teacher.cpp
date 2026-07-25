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

void PrintReversedOrder(int Num)
{
    int Remainder = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        cout << Remainder << endl;
    }
}

int main()
{
    PrintReversedOrder(ReadPositiveNumber("Please enter a number : "));
    return 0;
}