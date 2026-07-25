#include <iostream>
using namespace std;
int main()
{
    int MonthNumber;
    cout << "Enter Month Number : \n";
    cin >> MonthNumber;
    switch (MonthNumber)
    {
        case 1:
        cout << "its January";
        break;
        case 2:
        cout << "its February";
        break;
        case 3:
        cout << "its March";
        break;
        case 4:
        cout << "its April";
        break;
        case 5:
        cout << "its May";
        break;
        case 6:
        cout << "its June";
        break;
        case 7:
        cout << "its July";
        break;
        case 8:
        cout << "its August";
        break;
        case 9:
        cout << "its September";
        break;
        case 10:
        cout << "its October";
        break;
        case 11:
        cout << "its November";
        break;
        case 12:
        cout << "its December";
        break;
        default:
        cout << "Worng Month Number";
        break;
    }
    return 0;
}