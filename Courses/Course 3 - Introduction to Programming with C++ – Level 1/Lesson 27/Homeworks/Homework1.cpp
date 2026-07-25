#include <iostream>
using namespace std;
struct stPersonInfo
{
string Name;
string Gender;
int Age;
bool Is_Married;
};
struct stPlaceInfo
{
string Ip_Address;
string City;
string Country;
string Nationality;
};
struct stIncomeInfo
{
int Monthly_Salary;
int Yearly_Salary; 
};
struct stContactInfo
{
string Phone_Number;
string Email;
string Facebook_Account;
};
struct stPerson
{
stPersonInfo Personal_Information;
stPlaceInfo Location_Information;
stIncomeInfo Income_Information;
stContactInfo Contact_Information;
};
int main()
{
stPerson Person1;

Person1.Personal_Information.Name = "Abdullah Nori Shlgoom";
Person1.Personal_Information.Gender = "Male";
Person1.Personal_Information.Age = 17;
Person1.Personal_Information.Is_Married = false;

Person1.Location_Information.Ip_Address = "192.168.1.4";
Person1.Location_Information.City = "Misrata";
Person1.Location_Information.Country = "Libya";
Person1.Location_Information.Nationality = "Libyan";

Person1.Income_Information.Monthly_Salary = 3000;
Person1.Income_Information.Yearly_Salary = Person1.Income_Information.Monthly_Salary * 12;

Person1.Contact_Information.Phone_Number = "0935564736";
Person1.Contact_Information.Email = "TempGmail@gmail.com";
Person1.Contact_Information.Facebook_Account = "facebook.com/TempPage";

cout << Person1.Personal_Information.Name;
cout << endl << Person1.Income_Information.Yearly_Salary;
cout << endl << Person1.Location_Information.Nationality;
cout << endl << Person1.Location_Information.Country;
cout << endl << Person1.Contact_Information.Phone_Number;
return 0;
}