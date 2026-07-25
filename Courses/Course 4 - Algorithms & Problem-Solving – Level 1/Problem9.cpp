#include <iostream>
using namespace std;

void ReadNumbers(int Numbers [])
{
    for (int i = 0; i <= 2; i++)
    {
        cout << "Please Enter a Number: ";
        cin >> Numbers [i];
    }
}

int SumNumbers(int Numbers [])
{
    int Sum = 0;
    for (int i = 0; i <= 2; i++)
    {
        Sum += Numbers [i];
    }
    return Sum;
}

void PrintSum(int Sum)
{
    cout << "The Sum of Numbers is: " << Sum;
}
int main()
{
    int Numbers [3];
    ReadNumbers(Numbers);
    PrintSum(SumNumbers(Numbers));
    return 0;
}