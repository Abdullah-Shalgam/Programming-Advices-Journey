#include <iostream>
using namespace std;

enum enScreenColor {Red=1,Blue,Green,Yellow};

void ShowColorMenu()
{
    cout << "**************************************\n";
    cout << "              COLOR MENU              \n";
    cout << "**************************************\n\n";
    cout << "**************************************\n";
    cout << "Please Chose The Number of Your Color : \n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "**************************************\n\n";
    cout << "Your chose is : ";
}

enScreenColor ReadColor()
{
    int cl;
    cin >> cl;
    return (enScreenColor) cl;
}

void ColorName(enScreenColor ColorValue)
{
    switch (ColorValue)
    {
        case enScreenColor::Red:
        system("color 4F");
        break;
        case enScreenColor::Blue:
        system("color 1F");
        break;
        case enScreenColor::Green:
        system("color 2F");
        break;
        case enScreenColor::Yellow:
        system("color 6F");
        break;
        default:
        cout << "Something went wrong";
        break;
    }
}

int main()
{
    ShowColorMenu();
    ColorName(ReadColor());
    return 0;
}