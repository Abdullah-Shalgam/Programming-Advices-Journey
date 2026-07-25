#include <iostream>
using namespace std;
int main()
{
float BillValue;
cout << "Please enter the Bill Value: " << endl , cin >> BillValue;
float TotalBill = BillValue*1.1*1.16;
cout << endl << endl << TotalBill;
return 0;
}