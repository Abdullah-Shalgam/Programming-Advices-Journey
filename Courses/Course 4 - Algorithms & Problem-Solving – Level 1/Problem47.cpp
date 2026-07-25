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

float CaculateMonthsNeedToSettleLoan(float LoanAmount, float MonthlyPayment)
{
    return LoanAmount / MonthlyPayment;
}

void PrintMonthsNeed(float MonthsNeed)
{
    cout << "\nYou need " << MonthsNeed << " months to settle the loan";
}
int main()
{
    float LoanAmount = ReadPositiveNumber("Please enter the loan amount: ");
    float MonthlyPayment = ReadPositiveNumber("Please enter the monthly payment: ");
    float MonthsNeed = CaculateMonthsNeedToSettleLoan(LoanAmount, MonthlyPayment);
    PrintMonthsNeed(MonthsNeed);
    return 0;
}