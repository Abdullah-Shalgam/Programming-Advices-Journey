#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";

public:

    clsPerson(const string& FirstName, const string& LastName, const string& Email, const string& Phone)
        : _FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone)
    {
    }

    // Setters
    void SetFirstName(const string& FirstName) { _FirstName = FirstName; }
    void SetLastName(const string& LastName)   { _LastName = LastName; }
    void SetEmail(const string& Email)         { _Email = Email; }
    void SetPhone(const string& Phone)         { _Phone = Phone; }

    // Getters
    string GetFirstName() const { return _FirstName; }
    string GetLastName() const  { return _LastName; }
    string GetEmail() const     { return _Email; }
    string GetPhone() const     { return _Phone; }

    string GetFullName() const
    {
        return _FirstName + " " + _LastName;
    }

    virtual void Print() const
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << GetFullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }
};