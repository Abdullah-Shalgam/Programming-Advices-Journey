#pragma once
#include <iostream>
#include "clsEmployee.h"

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