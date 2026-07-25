#include <iostream>
using namespace std;
struct PersonalInformation
{
    string Name;
    string City;
    string Country;
    int MonthlySalary;
    int YearlySalary;
    string Gender;
    bool Married;
    int Age;
};
void ReadUserInfo(PersonalInformation &person)
{
    cout << "Please Enter your Name : " , getline(cin >> ws, person.Name);
    cout << "Please Enter your Age : " , cin >> person.Age;
    cout << "Please Enter your City : " , cin >> person.City;
    cout << "Please Enter your Country : " , cin >> person.Country;
    cout << "Please Enter your Monthly Salary : " , cin >> person.MonthlySalary;
    cout << "Please Enter your Gender M/F : " , cin >> person.Gender;
    cout << "Are you Married? (True/False): " , cin >> person.Married;
    person.YearlySalary = (person.MonthlySalary * 12);
}
void PrintUserInfo(PersonalInformation person)
{
    cout << "\n*************************************************";
    cout << "\nName : " << person.Name;
    cout << "\nAge is : " << person.Age << " Years old";
    cout << "\nCity : " << person.City;
    cout << "\nCountry : " << person.Country;
    cout << "\nGender : " << person.Gender;
    cout << "\nMarried : " << person.Married;
    cout << "\nMonthly Salary : " << person.MonthlySalary;
    cout << "\nYearly Salary : " << person.YearlySalary;
    cout << "\n*************************************************";
}
int main()
{
    PersonalInformation Person1;
    ReadUserInfo(Person1);
    PrintUserInfo(Person1);
    return 0;
}