#include <iostream>
using namespace std;
enum enGender {Male = 1 , Female};
enum enMarriageInfo {Single , Married};
enum enColors {Black , White , Red , Green , Yellow , Blue , Brown , Orange , Pink , Purple , Gray};
struct stPersonInfo
{
string Name;
enGender Gender;
int Age;
enMarriageInfo Is_Married;
enColors Favorite_Colour;
string Nationality;
};
struct stPlaceInfo
{
string Ip_Address;
string City;
string Country;
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
Person1.Personal_Information.Gender = enGender::Male;
Person1.Personal_Information.Age = 17;
Person1.Personal_Information.Is_Married = enMarriageInfo::Single;
Person1.Personal_Information.Favorite_Colour = enColors::Black;
Person1.Personal_Information.Nationality = "Libyan";

Person1.Location_Information.Ip_Address = "192.168.1.4";
Person1.Location_Information.City = "Misrata";
Person1.Location_Information.Country = "Libya";

Person1.Income_Information.Monthly_Salary = 3000;
Person1.Income_Information.Yearly_Salary = Person1.Income_Information.Monthly_Salary * 12;

Person1.Contact_Information.Phone_Number = "0935564736";
Person1.Contact_Information.Email = "TempGmail@gmail.com";
Person1.Contact_Information.Facebook_Account = "facebook.com/TempPage";

cout << Person1.Personal_Information.Name;
cout << endl << Person1.Income_Information.Yearly_Salary;
cout << endl << Person1.Personal_Information.Nationality;
cout << endl << Person1.Location_Information.Country;
cout << endl << Person1.Contact_Information.Phone_Number;
cout << endl << Person1.Personal_Information.Gender;
cout << endl << Person1.Personal_Information.Is_Married;
cout << endl << Person1.Personal_Information.Favorite_Colour;
return 0;
}