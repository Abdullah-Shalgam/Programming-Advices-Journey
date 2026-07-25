#include <iostream>
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
    cout << "Please Enter Your First Name : \n";
    cin >> Person.FirstName;
    cout << "Please Enter Your Last Name : \n";
    cin >> Person.LastName;
    cout << "Please Enter Your Age : \n";
    cin >> Person.Age;
    cout << "Please Enter your Phone Number : \n";
    cin >> Person.PhoneNumber;
}

void ReadAllPersonsInfo(stInformation Persons[2])
{
    cout << "*************************************************\n";
    ReadPersonInfo(Persons[0]); // نرسل العنصر الأول فقط
    cout << "*************************************************\n";
    ReadPersonInfo(Persons[1]); // نرسل العنصر الثاني فقط
    cout << "*************************************************\n\n";
}

// الدالة تستقبل شخص واحد فقط وتطبعه
void PrintPersonInfo(stInformation Person)
{
    cout << "First Name : " << Person.FirstName << endl;
    cout << "Last Name : " << Person.LastName << endl;
    cout << "Phone Number : " << Person.PhoneNumber << endl;
    cout << "Age : " << Person.Age << endl;
}

void PrintAllPersonsInfo(stInformation Persons[2])
{
    cout << "*************************************************\n";
    cout << "Person 1 Info:\n";
    PrintPersonInfo(Persons[0]);
    
    cout << "\n*************************************************\n";
    cout << "Person 2 Info:\n";
    PrintPersonInfo(Persons[1]);
    cout << "*************************************************\n";
}

int main()
{
    stInformation Persons[2];
    ReadAllPersonsInfo(Persons);
    PrintAllPersonsInfo(Persons);
    
    return 0;
}