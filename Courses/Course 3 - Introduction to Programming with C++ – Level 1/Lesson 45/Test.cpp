#include <iostream>
using namespace std;
int main()
{
    int day;
    cout << "Please Enter the day Number : \n";
    cin >> day;
    switch (day) 
    {
        case 1:
        cout << "It is sunday";
        break;
        case 2:
        cout << "It is Monday";
        break;
        case 3:
        cout << "It is Tuesday";
        break;
        case 4:
        cout << "It is Wednesday";
        break;
        case 5:
        cout << "It is Thursday";
        break;
        case 6:
        cout << "It is Friday";
        break;
        case 7:
        cout << "It is Saturday";
        break;
        default:
        cout << "Not a Week day Number!";
        break;
    }
    return 0;
}