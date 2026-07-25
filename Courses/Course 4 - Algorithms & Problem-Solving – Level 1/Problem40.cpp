#include <iostream>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    float Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
    } while (true);
}

float TotalBillWithServicesFee(float Num)
{
    return Num *= 1.1;
}

float TotalBillWithServicesFeeAndSalesTax(float TotalBillWithServicesFee)
{
    return TotalBillWithServicesFee *= 1.16;
}

void PrintResult(float TotaBillWithEvreyThing)
{
    cout << "\nTotal Bill = " << TotaBillWithEvreyThing;
}
int main()
{
    float BillValue = ReadPositiveNumber("Please enter the bill value: ");
    PrintResult(TotalBillWithServicesFeeAndSalesTax(TotalBillWithServicesFee(BillValue)));
    return 0;
}