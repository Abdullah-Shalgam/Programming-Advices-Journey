#include <iostream>
using namespace std;
int main()
{
    int DayNumber;
    cout << "Enter the Day Number : \n";
    cin >> DayNumber;
    switch (DayNumber)
    {
        case 1:
        cout << "its Sunday";
        break;
        case 2:
        cout << "its Monday";
        break;
        case 3:
        cout << "its Tuesday";
        break;
        case 4:
        cout << "its Wednesday";
        break;
        case 5:
        cout << "its Thursday";
        break;
        case 6:
        cout << "its Friday";
        break;
        case 7:
        cout << "its Saturday";
        break;
        default:
        cout << "Wrong Day Number";
        break;
    }
    return 0;
}