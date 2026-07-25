#include <iostream>
using namespace std;

struct stFullName
{
    string FirstName;
    string LastName;
};

stFullName ReadName()
{
    stFullName Person;

    cout << "Please Enter your first Name: ";
    cin >> Person.FirstName;

    cout << "Please Enter your Last Name: ";
    cin >> Person.LastName;

    return Person;
}

string GetFullName(stFullName Person, bool Reversed)
{
    string FullName = "";
    if (Reversed)
        FullName = (Person.LastName + " " + Person.FirstName);
    else
        FullName = (Person.FirstName + " " + Person.LastName);
    
    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\nYour Full Name is : " << FullName;
}

int main()
{
    PrintFullName(GetFullName(ReadName(), true));
    return 0;
}