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
    if (Color == enScreneColor::Red)
    {
        system("color 4F");
    }
    else if (Color == enScreneColor::Blue)
    {
        system("color 1F");
    }
    else if (Color == enScreneColor::Green)
    {
        system("color 2F");
    }
    else if (Color == enScreneColor::Yellow)
    {
        system("color 6F");
    }
    else
    {
        cout << "Something went wrong";
    }
    return 0;
}