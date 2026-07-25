#include <iostream>
#include <vector>
#include "InputLib.h"

using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

void ReadEmployeUntilSayNo(vector <stEmployee> & vEmployees)
{
    stEmployee TempEmploye;
    char Answer = 'y';
    do
    {
        TempEmploye.FirstName = InputLib::ReadText("Enter the first name: ");
        TempEmploye.LastName = InputLib::ReadText("Enter the last name: ");
        TempEmploye.Salary = InputLib::ReadFloatNumber("Enter the salary: ");
        vEmployees.push_back(TempEmploye);
        cout << "\nDo you want to add another Employee [Y/N]: ";
        cin >> Answer;
        cout << endl;
    } while (Answer == 'y' || Answer == 'Y');   
}

void PrintEmployeVector(const vector <stEmployee> & vEmployees)
{
    cout << "\nEmployees Vector: \n\n";

    for (const stEmployee & Employee : vEmployees)
    {
    cout << "FirstName: " << Employee.FirstName << endl;
    cout << "LastName : " << Employee.LastName << endl;
    cout << "Salary   : " << Employee.Salary << endl;
    cout << endl;
    }
    cout << endl;
}

int main()
{
    vector <stEmployee> vEmployees;
    ReadEmployeUntilSayNo(vEmployees);
    PrintEmployeVector(vEmployees);
    return 0;
}