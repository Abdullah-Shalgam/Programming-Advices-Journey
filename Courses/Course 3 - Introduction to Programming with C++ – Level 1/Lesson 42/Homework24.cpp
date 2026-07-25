#include <iostream>
using namespace std;
int main()
{
    int Age;
    cout << "Please Enter Your Age : \n";
    cin >> Age;
    if (Age >= 18 && Age <= 45)
    {
        cout << "Valid Age";
    }
    else
    {
        cout << "InValid Age";
    }
    return 0;
}