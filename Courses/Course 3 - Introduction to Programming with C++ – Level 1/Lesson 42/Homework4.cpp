#include <iostream>
using namespace std;
bool Hired()
{
    int Age;
    string DrivingLicense;
    cout << "Enter Your Age : \n";
    cin >> Age;
    cout << "Do you have a driving license? (Yes/No) : \n";
    cin >> DrivingLicense;
    if (Age >= 21 && DrivingLicense == "Yes")
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    if (Hired() == true)
    {
        cout << "Your are Haired";
    }
    else
    {
        cout << "Rejected";
    }
    return 0;
}