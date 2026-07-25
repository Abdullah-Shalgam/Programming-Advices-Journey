#include <iostream>
#include <string>

using namespace std;

struct stInformation
{
    string FirstName;
    string LastName;
    string PhoneNumber;
    int Age;
};

void ReadPersonInfo(stInformation &Person)
{
    cout << "Please Enter Your First Name: ";
    cin >> Person.FirstName;
    cout << "Please Enter Your Last Name: ";
    cin >> Person.LastName;
    cout << "Please Enter Your Age: ";
    cin >> Person.Age;
    cout << "Please Enter your Phone Number: ";
    cin >> Person.PhoneNumber;
    cout << endl;
}

void ReadAllPersonsInfo(stInformation Persons[], int NumPersons)
{
    for (int i = 0; i < NumPersons; i++)
    {
        cout << "Person [" << i + 1 << "] Data Entry:\n";
        ReadPersonInfo(Persons[i]);
    }
}

void PrintPersonInfo(const stInformation &Person)
{
    cout << "First Name   : " << Person.FirstName << endl;
    cout << "Last Name    : " << Person.LastName << endl;
    cout << "Age          : " << Person.Age << endl;
    cout << "Phone Number : " << Person.PhoneNumber << endl;
}

void PrintAllPersonsInfo(stInformation Persons[], int NumPersons)
{
    cout << "\n*************************************************\n";
    cout << "Displaying All Persons Info:\n";
    for (int i = 0; i < NumPersons; i++)
    {
        cout << "-----------------------\n";
        cout << "Person [" << i + 1 << "] Info:\n";
        PrintPersonInfo(Persons[i]);
    }
    cout << "*************************************************\n";
}

int main()
{
    int NumofPersons;
    cout << "How many persons do you want to enter? ";
    cin >> NumofPersons;

    stInformation Persons[100];
    
    ReadAllPersonsInfo(Persons, NumofPersons);
    PrintAllPersonsInfo(Persons, NumofPersons);

    return 0;
}