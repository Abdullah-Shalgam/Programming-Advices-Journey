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
        cout << "Invalid Input!";
    } while (true);
}

float CaculateMonthlyInstallment(float LoanAmount, float NumberofMonths)
{
    return LoanAmount / NumberofMonths;
}

void PrintMonthlyInstallment(float MonthlyIntallment, float NumberofMonths)
{
    cout << "\nYou need $" << MonthlyIntallment << " per month to settle the loan in " << NumberofMonths << " months";
}
int main()
{
    float LoanAmount = ReadPositiveNumber("Please enter the loan amount: ");
    float NumberofMonths = ReadPositiveNumber("Please enter the number of months to settle the loan: ");
    float MonthlyInstallment = CaculateMonthlyInstallment(LoanAmount, NumberofMonths);
    PrintMonthlyInstallment(MonthlyInstallment, NumberofMonths);
    return 0;
}