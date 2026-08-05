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

    clsEmployee(int ID, 
                const string& FirstName, 
                const string& LastName, 
                const string& Email, 
                const string& Phone, 
                const string& Title, 
                float Salary, 
                const string& Department)
        : clsPerson(ID, FirstName, LastName, Email, Phone),
          _Title(Title),
          _Salary(Salary),
          _Department(Department)
    {
    }

    // Setters
    void SetSalary(float Salary)                 { _Salary = Salary; }
    void SetTitle(const string& Title)           { _Title = Title; }
    void SetDepartment(const string& Department) { _Department = Department; }

    // Getters
    float Salary() const      { return _Salary; }
    string Title() const      { return _Title; }
    string Department() const { return _Department; }

    void Print() const
    {
        cout << "Info:\n\n";
        cout << "===================================\n";
        cout << "ID         : " << ID();
        cout << "\nFirstName  : " << FirstName();
        cout << "\nLastName   : " << LastName();
        cout << "\nFull Name  : " << FullName();
        cout << "\nEmail      : " << Email();
        cout << "\nPhone      : " << Phone();
        cout << "\nTitle      : " << Title();
        cout << "\nSalary     : " << Salary();
        cout << "\nDepartment : " << Department();
        cout << "\n===================================\n" << endl;
    }
};

int main()
{
    clsEmployee Employee1 ( 10, "Mohammed","Abu-Hadhoud","A@a.com","8298982","CEO", 5000, "ProgrammingAdvices" );

    Employee1.Print();

    return 0;
}