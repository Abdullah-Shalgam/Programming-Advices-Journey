#include <iostream>
#include <string>
using namespace std;

enum enSumType { Odd = 1, Even = 2, All = 3 };

int ReadNumber()
{
    int N;
    cout << "Please Enter the end of Numbers: ";
    cin >> N;
    return N;
}

bool IsEven(int Number)
{
    return (Number % 2 == 0);
}

enSumType GetSumType()
{
    string Choice;
    do
    {
        cout << "What do you want to Sum (All / Odd / Even): ";
        cin >> Choice;

        if (Choice == "All" || Choice == "all" || Choice == "ALL")
            return enSumType::All;
        else if (Choice == "Odd" || Choice == "odd" || Choice == "ODD")
            return enSumType::Odd;
        else if (Choice == "Even" || Choice == "even" || Choice == "EVEN")
            return enSumType::Even;
        
        cout << "Invalid choice! Please try again.\n";

    } while (true);
}

int SumFrom1toN(int N, enSumType SumType)
{
    int Sum = 0;

    for (int i = 1; i <= N; i++)
    {
        switch (SumType)
        {
        case enSumType::All:
            Sum += i;
            break;
        case enSumType::Even:
            if (IsEven(i)) Sum += i;
            break;
        case enSumType::Odd:
            if (!IsEven(i)) Sum += i;
            break;
        }
    }
    return Sum;
}

void PrintResult(int Sum, enSumType SumType)
{
    switch (SumType)
    {
    case enSumType::All:
        cout << "The sum of all numbers from 1 to N = " << Sum << endl;
        break;
    case enSumType::Even:
        cout << "The sum of even numbers from 1 to N = " << Sum << endl;
        break;
    case enSumType::Odd:
        cout << "The sum of odd numbers from 1 to N = " << Sum << endl;
        break;
    }
}

int main()
{
    int N = ReadNumber();
    cout << endl;

    enSumType SumType = GetSumType();
    cout << endl;

    PrintResult(SumFrom1toN(N, SumType), SumType);

    return 0;
}