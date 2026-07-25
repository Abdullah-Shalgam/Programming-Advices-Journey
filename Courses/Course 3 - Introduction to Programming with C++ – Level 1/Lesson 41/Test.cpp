#include <iostream>
using namespace std;

struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};

int main()
{
    strInfo Persons[2];

    Persons[0].FirstName = "Mohammed";
    Persons[0].LastName = "Abu-Hadhoud";
    Persons[0].Age = 44;
    Persons[0].Phone = "89827787";

    Persons[1].FirstName = "Ali";
    Persons[1].LastName = "Maher";
    Persons[1].Age = 22;
    Persons[1].Phone = "5432344";

    cout << Persons[1].FirstName;

    return 0;
}