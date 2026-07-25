#include <iostream>
using namespace std;

enum enOperationType {Plus = '+', Minus = '-', Divide = '/', Multiply = '*'};

const int ArrayLength = 2;

float ReadNumber(string Msg)
{
    float Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

enOperationType GetOperationType()
{
    char OT;
    do
    {
        cout << "Please Enter the operation type ( +, -, *, /): ";
        cin >> OT;
        if (OT == '+' || OT == '-' || OT == '*' || OT == '/')
            return (enOperationType) OT;
        else
            cout << "Invalid Input!\n";
    } while (true);
}

float OperationResult(float Nums[ArrayLength], enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Plus:
        return Nums[0] + Nums[1];
    case enOperationType::Minus:
        return Nums[0] - Nums[1];
    case enOperationType::Multiply:
        return Nums[0] * Nums[1];
    case enOperationType::Divide:
        do
        {
            if (Nums[1] != 0)
            {
                return Nums[0] / Nums[1];
            }
            cout << "Error: Division by zero!\n";
            Nums[1] = ReadNumber("Please Enter the second number again: ");
        } while (true);
    default:
        return 0;
    }
}

void PrintResult(float Nums[ArrayLength], enOperationType OperationType, float Result)
{
    cout << "\n\n" << Nums[0] << " " << (char) OperationType << " " << Nums[1] << " = " << Result;
}

int main()
{
    float Nums[ArrayLength];
    Nums[0] = ReadNumber("Please Enter the first number: ");
    Nums[1] = ReadNumber("Please Enter the second number: ");
    enOperationType OperationType = GetOperationType();
    float Result = OperationResult(Nums, OperationType);
    PrintResult(Nums, OperationType, Result);
    return 0;
}