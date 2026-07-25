#include <iostream>
using namespace std;
enum enScreneColor {Red=1, Blue=2, Green=3, Yellow=4};
int main()
{
    cout << "*************************************\n";
    cout << "Please Chose The Number of Your Color\n";
    cout << "(1) Red\n";
    cout << "(2) Blue\n";
    cout << "(3) Green\n";
    cout << "(4) Yellow\n";
    cout << "*************************************\n\n";
    cout << "Your chose is : ";
    int c;
    enScreneColor Color;
    cin >> c;
    Color = (enScreneColor) c;
    switch (Color)
    {
        case enScreneColor::Red:
        system("color 4F");
        break;
        case enScreneColor::Blue:
        system("color 1F");
        break;
        case enScreneColor::Green:
        system("color 2F");
        break;
        case enScreneColor::Yellow:
        system("color 6F");
        break;
        default:
        cout << "Something went wrong";
        break;
    }
    return 0;
}