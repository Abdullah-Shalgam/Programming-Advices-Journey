#include <iostream>
using namespace std;
int main()
{
float TotalBill , CashPaid;
cout << "Please enter the Total Bill: " << endl , cin >> TotalBill;
cout << "Please enter the Cash Paid: " << endl , cin >> CashPaid;
float PaidBack = CashPaid-TotalBill;
cout << endl << endl << PaidBack;
return 0;
}