#include <iostream>
using namespace std;
struct structInfo
{
    string Name;
    string Country;
    int Age;
    string Phone; 
};
void ReadInfo(structInfo &personInfo)
{
    cout << "Please Enter your Name : " , getline(cin >> ws, personInfo.Name);
    cout << "Please Enter your Country : " , cin >> personInfo.Country;
    cout << "Please Enter your Age : " , cin >> personInfo.Age;
    cout << "Please Enter you Phone Number : " , cin >> personInfo.Phone;
}
void printInfo(structInfo personInfo)
{
    cout << "Name is : " << personInfo.Name;
    cout << "\nCountry is : " << personInfo.Country;
    cout << "\nAge is : " << personInfo.Age;
    cout << "\nPhone Number is : " << personInfo.Phone;
}
int main()
{
    structInfo Peronal_Info;
    ReadInfo(Peronal_Info);
    printInfo(Peronal_Info);
    return 0;
}