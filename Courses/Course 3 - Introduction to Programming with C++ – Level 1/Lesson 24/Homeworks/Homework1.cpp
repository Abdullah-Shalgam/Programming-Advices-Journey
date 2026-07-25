#include <iostream>
using namespace std;
int main()
{
int A , B;
cout << "Please enter the first Number: " << endl , cin >> A;
cout << "Please enter the second Number: " << endl , cin >> B;
cout << endl << A << " = " << B << " is " << (A==B) << endl;
cout << A << " != " << B << " is "  << (A!=B) << endl;
cout << A << " < " << B << " is "  << (A<B) << endl;
cout << A << " > " << B << " is "  << (A>B) << endl;
cout << A << " <= " << B << " is "  << (A<=B) << endl;
cout << A << " >= " << B << " is "  << (A>=B) << endl;
return 0;
}