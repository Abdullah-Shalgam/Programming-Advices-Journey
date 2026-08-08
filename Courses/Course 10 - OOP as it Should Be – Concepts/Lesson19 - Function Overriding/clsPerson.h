#pragma once
#include <iostream>

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