#include <iostream>
using namespace std;

float ReadTotalSales()
{
    float TotalSales;
    do
    {
        cout << "Please enter your Total Sales: ";
        cin >> TotalSales;
        if (TotalSales >= 0)
            return TotalSales;
        cout << "Invalid Input!";
    } while (true);
}

float GetCommissionPercentage(float TotalSales)
{
    if (TotalSales > 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02;
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0;
}

float CalculateTotalCommission(float TotalSales, float CommissionPercentage)
{
    return TotalSales * CommissionPercentage;
}

void PrintResult(float TotalCommission)
{
    cout << "\nYour Total Commission is: " << TotalCommission;
}
int main()
{
    float TotalSales = ReadTotalSales();
    float CommissionPercentage = GetCommissionPercentage(TotalSales);
    float TotalCommission = CalculateTotalCommission(TotalSales, CommissionPercentage);
    PrintResult(TotalCommission);
    return 0;
}