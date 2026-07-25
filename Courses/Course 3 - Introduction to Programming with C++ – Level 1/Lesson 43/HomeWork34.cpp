#include <iostream>
using namespace std;
int main()
{
    int TotalSales;
    cout << "Enter the Total Sales : \n";
    cin >> TotalSales;
    if (TotalSales >= 1000000)
    {
        cout << TotalSales * 1.01;
    }
    else if (TotalSales <= 1000000 && TotalSales >= 500000)
    {
        cout << TotalSales * 1.02;
    }
    else if (TotalSales <= 500000 && TotalSales >= 100000)
    {
        cout << TotalSales * 1.03;
    }
    else if (TotalSales <= 100000 && TotalSales >= 50000)
    {
        cout << TotalSales * 1.05;
    }
    else
    {
        cout << "0";
    }
    return 0;
}