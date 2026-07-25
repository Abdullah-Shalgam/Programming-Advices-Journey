#include <iostream>
using namespace std;
int main()
{
float Number1 , Number2 , Temp;
cout << "Please enter the first Number: " << endl , cin >> Number1;
cout << "Please enter the second Number: " << endl , cin >> Number2;
cout << endl << endl << endl << Number1 << endl << Number2;
Temp = Number1;
Number1 = Number2;
Number2 = Temp;
cout << endl << endl << Number1 << endl << Number2;
return 0;
}