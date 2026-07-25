#include <iostream>
using namespace std;

const int ArrayLength = 5;

void ReadNumbers(int Numbers [ArrayLength])
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Please Enter a Number: ";
        cin >> Numbers [i];
    }
}

int SumNumbers(int Numbers [ArrayLength])
{
    int Sum = 0;
    for (int i = 0; i < ArrayLength; i++)
    {
        Sum += Numbers [i];
    }
    return Sum;
}

float AvgNumbers(int Sum)
{
    return (float)Sum/ArrayLength;
}

void PrintSum(int Sum)
{
    cout << "\nThe Sum of Numbers is: " << Sum;
}

void PrintAvg(float Avg)
{
    cout << "\n\nThe Averege of Numbers is: " << Avg;
}

int main()
{
    int Numbers [ArrayLength];
    ReadNumbers(Numbers);
    int Sum = SumNumbers(Numbers);
    PrintSum(Sum);
    PrintAvg(AvgNumbers(Sum));
    return 0;
}