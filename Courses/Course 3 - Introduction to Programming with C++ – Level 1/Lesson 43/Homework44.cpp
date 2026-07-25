#include <iostream>
using namespace std;
int main()
{
    int DayNumber;
    cout << "Enter the Day Number : \n";
    cin >> DayNumber;
    if (DayNumber == 1)
    {
        cout << "its Sunday";
    }
    else if (DayNumber == 2)
    {
        cout << "its Monday";
    }
    else if (DayNumber == 3)
    {
        cout << "its Tuesday";
    }
    else if (DayNumber == 4)
    {
        cout << "its Wednesday";
    }
    else if (DayNumber == 5)
    {
        cout << "its Thursday";
    }
    else if (DayNumber == 6)
    {
        cout << "its Friday";
    }
    else if (DayNumber == 7)
    {
        cout << "its Saturday";
    }
    else
    {
        cout << "Wrong Day Number";
    }
    return 0;
}