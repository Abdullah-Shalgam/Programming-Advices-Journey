#include <iostream>
using namespace std;
int main()
{
    float Grade;
    cout << "Please Enter Your Grade : \n";
    cin >> Grade;
    if (Grade >= 90 && Grade <= 100)
    {
        cout << "A";
    }
    else if (Grade >= 80 && Grade <= 89)
    {
        cout << "B";
    }
    else if (Grade >= 70 && Grade <= 79)
    {
        cout << "C";
    }
    else if (Grade >= 60 && Grade <= 69)
    {
        cout << "D";
    }
    else if (Grade >= 50 && Grade <= 59)
    {
        cout << "E";
    }
    else
    {
        cout << "F";
    }
    return 0;
}