#include <iostream>

using namespace std;

class clsPerson
{
    private:
        int x = 0;
        string S1 = "";

    public:
        string FirstName = "";
        string LastName = "";

        string GetFullName()
        {
            return FirstName + " " + LastName;
        }
};

int main()
{
    clsPerson Person1, Person2;

    Person1.FirstName = "Ali";
    Person1.LastName = "Al-Ganodi";

    Person2.FirstName = "Khalid";
    Person2.LastName = "Al-Ganodi";

    cout << "Person1 Full Name: " << Person1.GetFullName();
    cout << "\nPerson2 Full Name: " << Person2.GetFullName();

    return 0;
}