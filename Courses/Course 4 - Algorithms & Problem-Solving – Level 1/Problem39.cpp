#include <iostream>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    float Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

float CalculatRemainderPaidBack(float TotalBill, float TotalPaid)
{
    return TotalPaid - TotalBill;
}

void PrintResult(float TotalBill, float TotalPaid)
{
    if (TotalBill > TotalPaid)
        cout << "\nThe customer still owes $" << abs(CalculatRemainderPaidBack(TotalBill, TotalPaid));
    else
        cout << "\nGive the customer $" << CalculatRemainderPaidBack(TotalBill, TotalPaid);
}
int main()
{
    float TotalBill = ReadPositiveNumber("Please enter the total bill: ");
    float TotalPaid = ReadPositiveNumber("Please enter the total cash paid: ");
    PrintResult(TotalBill, TotalPaid);
    return 0;
}