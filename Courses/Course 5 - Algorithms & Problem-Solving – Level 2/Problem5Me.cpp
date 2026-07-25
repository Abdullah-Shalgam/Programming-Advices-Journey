#include <iostream>
#include <string>
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

int NumberLength(int Num)
{
    return to_string(Num).length();
}

void PrintReversedOrder(int Num)
{
    for (int i = NumberLength(Num) - 1; i >= 0; i--)
    {
        cout << to_string(Num) [i] << endl;
    }
}

int main()
{
    int Num = ReadPositiveNumber("Please enter a number : ");
    PrintReversedOrder(Num);
    return 0;
}