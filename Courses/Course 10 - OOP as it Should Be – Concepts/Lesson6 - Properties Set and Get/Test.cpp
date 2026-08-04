#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _FirstName = "";
    string _LastName = "";

public:
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string FirstName()
    {
        return _FirstName;
    }
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    string LastName()
    {
        return _LastName;
    }
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Ali");
    Person1.setLastName("Al-Ganodi");

    cout << "Person1 Details:\n\n";
    cout << "FirstName: " << Person1.FirstName();
    cout << "\nLastName: " << Person1.LastName();
    cout << "\nFullName: " << Person1.FullName();

    return 0;
}