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

    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    int ID()
    {
        return _ID;
    }

    string FirstName()
    {
        return _FirstName;
    }

    string LastName()
    {
        return _LastName;
    }

    string Email()
    {
        return _Email;
    }

    string Phone()
    {
        return _Phone;
    }

    string FullName()
    {
        return FirstName() + " " + LastName();
    }

    void Print()
    {
        cout << "Info:\n\n";
        cout << "===================================\n";
        cout << "ID       : " << ID();
        cout << "\nFirstName: " << FirstName();
        cout << "\nLastName : " << LastName();
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << Email();
        cout << "\nPhone    : " << Phone();
        cout << "\n===================================\n" << endl;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "The following message sent successfully to email: " << Email();
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl << endl;
    }

    void SendSMS(string Msg)
    {
        cout << "The following SMS message sent successfully to phone: " << Phone();
        cout << "\nMessage: " << Msg << endl << endl;
    }
};

int main()
{
    clsPerson Person1(10, "Ali", "Al-Ganodi", "koko@gmail.com", "0933487529");
    Person1.Print();

    Person1.SendEmail("Hi", "How are you?");
    Person1.SendSMS("How are you?");
    
    return 0;
}