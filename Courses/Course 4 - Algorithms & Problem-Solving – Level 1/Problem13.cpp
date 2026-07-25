#include <iostream>
using namespace std;

const int ArrayLength = 3;

void ReadNumbers(int Numbers [ArrayLength])
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Please Enter the Number " << i+1 << " : ";
        cin >> Numbers [i];
    }
}

int CheckGreater(int Numbers [ArrayLength])
{
    int Max = Numbers [0];
    for (int i = 1; i < ArrayLength; i++)
    {
        if (Numbers [i] > Max)
        {
            Max = Numbers [i];
        }
    }
    return Max;
}

void PrintLargerNumber(int LargerNumber)
{
    cout << "\nThe Larger Number is: " << LargerNumber;
}

int main()
{
    int Numbers [ArrayLength];
    ReadNumbers(Numbers);
    PrintLargerNumber(CheckGreater(Numbers));
    return 0;
}