#include <iostream>
using namespace std;

string ReadNameofUser()
{
    string Name;
    cout << "Please Enter Your Name: ";
    getline(cin, Name);
    return Name;
}

void PrintName(string Name)
{
    cout << "\n\nYour Name is : " << Name;
}

int main()
{
    PrintName(ReadNameofUser());
    return 0;
}