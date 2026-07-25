#include <iostream>
using namespace std;
int main()
{
int Number;
string Name , Country;
cout << "Please enter Employee Number:\n" , cin >> Number;
cin.ignore(1, '\n');
cout << "Please enter the Full Name:\n" , getline(cin, Name);
cout << "Please enter your Country:\n" , cin >> Country;
cout << "Number: " << Number << ", Name: " << Name << ", Country: " << Country;
return 0;
}