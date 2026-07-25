#include <iostream>
using namespace std;

struct stPiggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

int ReadPositiveNumber(string Message)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
        if (Number >= 0) return Number;
        cout << "Invalid Input!\n";
    } while (true);
}

stPiggyBankContent ReadPiggyBankContent()
{
    stPiggyBankContent PiggyBankContent;
    PiggyBankContent.Pennies = ReadPositiveNumber("Please Enter the Pennies: ");
    PiggyBankContent.Nickels = ReadPositiveNumber("Please Enter the Nickels: ");
    PiggyBankContent.Dimes = ReadPositiveNumber("Please Enter the Dimes: ");
    PiggyBankContent.Quarters = ReadPositiveNumber("Please Enter the Quarters: ");
    PiggyBankContent.Dollars = ReadPositiveNumber("Please Enter the Dollars: ");
    return PiggyBankContent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
    int P_Nickels = 5;
    int P_Dimes = 10;
    int P_Quarters = 25;
    int P_Dollars = 100;
    return PiggyBankContent.Pennies + (PiggyBankContent.Nickels* P_Nickels) + (PiggyBankContent.Dimes * P_Dimes) + (PiggyBankContent.Quarters * P_Quarters) + (PiggyBankContent.Dollars * P_Dollars);
}

float CalculateTotalDollars(int TotalPennies)
{
    return float(TotalPennies) / 100;
}

void PrintResult(int TotalPennies, float TotalDollars)
{
    cout << "\n\nTotal Pennies = " << TotalPennies << endl;
    cout << "Total Dollars = " << TotalDollars;
}
int main()
{
    stPiggyBankContent PiggyBankContent = ReadPiggyBankContent();
    int TotalPennies = CalculateTotalPennies(PiggyBankContent);
    float TotalDollars = CalculateTotalDollars(TotalPennies);
    PrintResult(TotalPennies, TotalDollars);
    return 0;
}