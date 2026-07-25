#include <iostream>
using namespace std;
int main()
{
int LoanAmount , MonthsNeed;
cout << "Please enter the Loan Amount: " << endl , cin >> LoanAmount;
cout << "Please enter the Months you need to settle the loan: " << endl , cin >> MonthsNeed;
cout << endl << endl << LoanAmount/MonthsNeed;
return 0;
}