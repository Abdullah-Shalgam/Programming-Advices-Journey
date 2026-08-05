#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. BASE CLASS: clsPerson
// ==========================================
class clsPerson
{
private:
    int _ID = 0;
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";

public:

    clsPerson(int ID, 
              const string& FirstName, 
              const string& LastName, 
              const string& Email, 
              const string& Phone)
        : _ID(ID), 
          _FirstName(FirstName), 
          _LastName(LastName), 
          _Email(Email), 
          _Phone(Phone)
    {
    }

    // Setters
    void SetFirstName(const string& FirstName) { _FirstName = FirstName; }
    void SetLastName(const string& LastName)   { _LastName = LastName; }
    void SetEmail(const string& Email)         { _Email = Email; }
    void SetPhone(const string& Phone)         { _Phone = Phone; }

    // Getters
    int ID() const           { return _ID; }
    string FirstName() const { return _FirstName; }
    string LastName() const  { return _LastName; }
    string Email() const     { return _Email; }
    string Phone() const     { return _Phone; }

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
        cout << "\nBody   : " << Body << endl << endl;
    }

    void SendSMS(const string& Msg) const
    {
        cout << "The following SMS message sent successfully to phone: " << _Phone;
        cout << "\nMessage: " << Msg << endl << endl;
    }
};

// ==========================================
// 2. DERIVED CLASS: clsEmployee
// ==========================================
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
        cout << "\nTitle      : " << _Title;
        cout << "\nSalary     : " << _Salary;
        cout << "\nDepartment : " << _Department;
        cout << "\n===================================\n" << endl;
    }
};

// ==========================================
// 3. DERIVED CLASS: clsDeveloper
// ==========================================
class clsDeveloper : public clsEmployee
{
private:
    string _MainProgLang = "";

public:

    clsDeveloper(int ID, 
                 const string& FirstName, 
                 const string& LastName, 
                 const string& Email, 
                 const string& Phone, 
                 const string& Title, 
                 float Salary, 
                 const string& Department,
                 const string& MainProgLang)
        : clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Salary, Department),
          _MainProgLang(MainProgLang)
    {
    }

    // Setters
    void SetMainProgrammingLanguage(const string& MainProgLang) { _MainProgLang = MainProgLang; }

    // Getters
    string MainProgrammingLanguage() const { return _MainProgLang; }

    void Print() const
    {
        cout << "Info:\n\n";
        cout << "===================================\n";
        cout << "ID            : " << ID();
        cout << "\nFirstName     : " << FirstName();
        cout << "\nLastName      : " << LastName();
        cout << "\nFull Name     : " << FullName();
        cout << "\nEmail         : " << Email();
        cout << "\nPhone         : " << Phone();
        cout << "\nTitle         : " << Title();
        cout << "\nSalary        : " << Salary();
        cout << "\nDepartment    : " << Department();
        cout << "\nProg Language : " << MainProgrammingLanguage();
        cout << "\n===================================\n" << endl;
    }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    clsDeveloper Developer1(10, "Ali", "Al-Ganodi", "Ali@gmail.com", "0912345678", 
                           "Software Engineer", 5000, "IT", "C++");

    Developer1.Print();

    Developer1.SendEmail("Task Update", "The project code is clean and refactored.");
    Developer1.SendSMS("Hello World!");

    return 0;
}