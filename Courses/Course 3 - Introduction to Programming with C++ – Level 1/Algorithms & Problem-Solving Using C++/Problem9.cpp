#include <iostream>
using namespace std;
int main()
{
float Number1 , Number2 , Number3;
cout << "Please enter the first Number: " << endl , cin >> Number1;
cout << "Please enter the second Number: " << endl , cin >> Number2;
cout << "Please enter the third Number: " << endl , cin >> Number3;
float Sum = Number1 + Number2 + Number3;
cout << endl << Sum;
return 0;
}