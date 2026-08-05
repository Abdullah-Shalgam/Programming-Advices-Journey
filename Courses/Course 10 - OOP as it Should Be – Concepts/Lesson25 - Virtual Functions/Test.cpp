#include <iostream>

using namespace std;

class clsPerson
{
public:
    virtual void Print()
    {
        cout << "Hi, i'm a person!\n ";
    }
};

class clsEmployee : public clsPerson
{
public:
    void Print() override
    {
        cout << "Hi, I'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    void Print() override
    {
        cout << "Hi, I'm a student\n";
    }
};

int main()
{
    clsEmployee Employee1;
    clsStudent Student1;

    clsPerson * Person1 = &Employee1;
    Person1->Print();

    Person1 = &Student1;
    Person1->Print();

    return 0;
}