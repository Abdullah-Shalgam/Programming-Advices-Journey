#include <iostream>
using namespace std;

const int ArrayLength = 2;

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
    if(Numbers [0] > Numbers [1])
        return Numbers [0];
    else
        return Numbers [1];
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