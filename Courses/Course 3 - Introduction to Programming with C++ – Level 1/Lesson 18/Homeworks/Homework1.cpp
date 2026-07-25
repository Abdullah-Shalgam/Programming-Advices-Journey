#include <iostream>
using namespace std;
int main()
{

string Name , City , Country;
unsigned short int Age;
float Monthly_Salary , Yearly_Salary;
char Gender;
bool isMarried;
cout << "Please enter your Name: " , cin >> Name;
cout << "Please enter your Age: " , cin >> Age;
cout << "Please enter your City: " , cin >> City;
cout << "Please enter your Country:" , cin >> Country;
cout << "Please enter your Monthly Salary: " , cin >> Monthly_Salary;
cout << "Please enter your Gender (if Male write M) , (if Female wirte F): " , cin >> Gender;
cout << "Are you married? (if Yes write 1) , (if No write 0): " , cin >> isMarried;
cout << "*******************************************************************************************************\n";
cout << "Name: " << Name << endl;
cout << "Age: " << Age << endl;
cout << "City: " << City << endl;
cout << "Country: " << Country << endl;
cout << "Monthly Salary: " << Monthly_Salary << endl;
cout << "Yearly Salary: " << Monthly_Salary * 12 << endl;
cout << "Gender: " << Gender << endl;
cout << "Married: " << isMarried << endl;
cout << "*******************************************************************************************************";
return 0;
}