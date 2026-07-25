#include <iostream>
#include <string>
using namespace std;
void PrintTheUserName()
{
    string UserName;
    cout << "Please enter your full Name:" << endl , getline(cin,UserName);
    cout << "Welcome " << UserName << " How i can help you today!";
}
int main()
{
    PrintTheUserName();
}