#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
    int _ID = 0;
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";

public:

    clsPerson()
    {
    }

    // 1. استخدام Member Initializer List + const string&
    clsPerson(int ID, const string& FirstName, const string& LastName, const string& Email, const string& Phone)
        : _ID(ID), _FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone)
    {
    }

    // Setters - استخدام const string& لأداء أسرع
    void SetFirstName(const string& FirstName) { _FirstName = FirstName; }
    void SetLastName(const string& LastName)   { _LastName = LastName; }
    void SetEmail(const string& Email)         { _Email = Email; }
    void SetPhone(const string& Phone)         { _Phone = Phone; }

    // Getters - إضافة const لأنها قراءة فقط + الوصول المباشر للـ Members بالداخل
    int ID() const { return _ID; }
    string FirstName() const { return _FirstName; }
    string LastName() const  { return _LastName; }
    string Email() const     { return _Email; }
    string Phone() const     { return _Phone; }

    // استخدام المتغيرات مباشرة بالداخل أسرع وأوضح
    string FullName() const
    {
        return _FirstName + " " + _LastName;
    }

    void Print() const
    {
        cout << "Info:\n\n";
        cout << "===================================\n";
        cout << "ID       : " << _ID;
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
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

class clsEmployee : public clsPerson
{
private:
    float _Salary = 0;
    string _Title = "";
    string _Department = "";

public:

    // Setters
    void SetSalary(float Salary)                 { _Salary = Salary; }
    void SetTitle(const string& Title)           { _Title = Title; }
    void SetDepartment(const string& Department) { _Department = Department; }

    // Getters
    float Salary() const      { return _Salary; }
    string Title() const      { return _Title; }
    string Department() const { return _Department; }
};

int main()
{
    clsEmployee Employee1;
    
    Employee1.SetFirstName("Mohammed");
    Employee1.SetLastName("Abu-Hadhoud");
    Employee1.SetEmail("a@a.com");

    Employee1.Print();

    Employee1.SendEmail("Hi", "How are you?");

    Employee1.SetSalary(5000);
    cout << "Salary is: " << Employee1.Salary();

    Employee1.Print();

    return 0;
}