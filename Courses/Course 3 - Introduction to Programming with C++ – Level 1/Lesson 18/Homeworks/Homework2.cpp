#include <iostream>
using namespace std;
int main()
{

float Number1 , Number2 , Number3;
cout << "Please enter the first Number: " , cin >> Number1;
cout << "please enter the secend Number: " , cin >> Number2;
cout << "please enter the third Number: " , cin >> Number3;
cout << Number1 << "+" << endl;
cout << Number2 << "+" << endl;
cout << Number3 << endl;
cout << "-----------------------------------------------------\n";
cout << "Total is: " << Number1 + Number2 + Number3 << endl << endl << endl << endl << endl;
unsigned short int UserAge;
cout << "Please enter your Age: " , cin >> UserAge , cout << endl;
cout << "After 5 years you will be " << UserAge + 5 <<" years old.";
return 0;
}