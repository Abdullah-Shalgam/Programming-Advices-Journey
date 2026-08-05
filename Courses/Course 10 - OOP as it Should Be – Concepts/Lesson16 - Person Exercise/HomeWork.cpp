#include <iostream>
#include <string>

using namespace std;

class clsEmployee
{
private:
    int _ID = 0;
    float _Salary = 0;
    string _FirstName = "";
    string _LastName = "";
    string _Title = "";
    string _Email = "";
    string _Phone = "";
    string _Department = "";

public:

    clsEmployee(int ID, 
                const string& FirstName, 
                const string& LastName, 
                const string& Title,
                const string& Email, 
                const string& Phone, 
                float Salary, 
                const string& Department) 
        : _ID(ID), 
          _FirstName(FirstName), 
          _LastName(LastName), 
          _Title(Title),
          _Email(Email), 
          _Phone(Phone), 
          _Salary(Salary), 
          _Department(Department)
    {
    }

    // Setters
    void SetFirstName(const string& FirstName)   { _FirstName = FirstName; }
    void SetLastName(const string& LastName)     { _LastName = LastName; }
    void SetTitle(const string& Title)           { _Title = Title; }
    void SetEmail(const string& Email)           { _Email = Email; }
    void SetPhone(const string& Phone)           { _Phone = Phone; }
    void SetSalary(float Salary)                 { _Salary = Salary; }
    void SetDepartment(const string& Department) { _Department = Department; }

    // Getters
    int ID() const            { return _ID; }
    string FirstName() const  { return _FirstName; }
    string LastName() const   { return _LastName; }
    string Title() const      { return _Title; }
    string Email() const      { return _Email; }
    string Phone() const      { return _Phone; }
    float Salary() const      { return _Salary; }
    string Department() const { return _Department; }

    string FullName() const 
    {
        return _FirstName + " " + _LastName; 
    }

    void Print() const
    {
        cout << "Info:\n\n";
        cout << "===================================\n";
        cout << "ID         : " << _ID;
        cout << "\nFirstName  : " << _FirstName;
        cout << "\nLastName   : " << _LastName;
        cout << "\nFull Name  : " << FullName();
        cout << "\nTitle      : " << _Title;
        cout << "\nEmail      : " << _Email;
        cout << "\nPhone      : " << _Phone;
        cout << "\nSalary     : " << _Salary;
        cout << "\nDepartment : " << _Department;
        cout << "\n===================================\n" << endl;
    }

    void SendEmail(const string& Subject, const string& Body) const
    {
        cout << "The following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl << endl;
    }

    void SendSMS(const string& Msg) const
    {
        cout << "The following SMS message sent successfully to phone: " << _Phone;
        cout << "\nMessage: " << Msg << endl << endl;
    }
};

int main()
{
    clsEmployee Employee1(10, "Ali", "Al-Ganodi", "Developer", "KoKo@gmail.com", "0934835834", 5000, "IT");
    
    Employee1.Print();

    Employee1.SendEmail("Hi", "How are you?");
    Employee1.SendSMS("How are you?");

    return 0;
}