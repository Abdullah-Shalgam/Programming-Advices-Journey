#include <iostream>
using namespace std;
int main()
{
int P , N , d , Q , D;
cout << "Please enter the number of Pennies: " << endl , cin >> P;
cout << "Please enter the number of Nickels: " << endl , cin >> N;
cout << "Please enter the number of Dimes: " << endl , cin >> d;
cout << "Please enter the number of Quarters: " << endl , cin >> Q;
cout << "Please enter the number of Dollars: " << endl , cin >> D;
float Total_P = P + (N*5) + (d*10) + (Q*25) + (D*100);
float Total_D = Total_P/100;
cout << endl << endl << Total_P << " Pennies" << endl << Total_D << " Dollars";
return 0;
}