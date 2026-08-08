#pragma once
#include <iostream>
#include "clsPerson.h"

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