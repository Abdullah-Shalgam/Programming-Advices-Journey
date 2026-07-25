#include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

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

enPassFail CheckPassFail(float Avg)
{
    if (Avg >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintSum(int Sum)
{
    cout << "\nThe Sum of Numbers is: " << Sum;
}

void PrintAvg(float Avg)
{
    cout << "\n\nThe Averege of Numbers is: " << Avg;
}

void PrintPassFail(enPassFail PassFail)
{
    if (PassFail == enPassFail::Pass)
        cout << "\nYou Passed";
    else
        cout << "\nYou Faild";
}

int main()
{
    int Numbers [ArrayLength];
    ReadNumbers(Numbers);
    int Sum = SumNumbers(Numbers);
    float Avg = AvgNumbers(Sum);
    enPassFail PassFail = CheckPassFail(Avg);
    PrintAvg(Avg);
    PrintPassFail(PassFail);
    return 0;
}