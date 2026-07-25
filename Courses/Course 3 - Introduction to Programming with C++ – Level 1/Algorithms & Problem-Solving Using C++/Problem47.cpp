#include <iostream>
using namespace std;
int main()
{
int LoanAmount , MonthlyPayment;
cout << "Please enter the Loan Amount: " << endl , cin >> LoanAmount;
cout << "Please enter the Monthly Payment: " << endl , cin >> MonthlyPayment;
cout << endl << endl << LoanAmount/MonthlyPayment << " Months";
return 0;
}