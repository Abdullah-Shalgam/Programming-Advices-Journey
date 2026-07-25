#include <iostream>
using namespace std;
int main()
{
string Name = "Mohammed Abo-Hodhoud" , Country = "Jordan" , City = "Amman";
unsigned short int Age = 44;
unsigned short int Monthly_Salary = 5000;
char Gender = 'M';
bool isMarried = true;

cout << "*************************************\n" << "Name: " << Name << endl << "Age: " << Age << endl;
cout << "City: " << City << endl << "Country: " << Country << endl << "Monthly Salary: " << Monthly_Salary << endl;
cout << "Yearly Salary: " << Monthly_Salary * 12<< endl << "Gender: " << Gender << endl << "Married: " << isMarried << endl;
cout << "*************************************";


return 0;

}