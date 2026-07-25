#include <iostream>
#include <cstdlib>
using namespace std;
void ReadData(char &l)
{
    cout << "Do you want to print all small or capital litters (S/C) : \n";
    cin >> l;
}
void PrintAllSmallLitters()
{
    for (int i = 97; i <= 122; i++)
    {
        cout << char(i) << endl;
    }
}
void PrintAllCapitalLitters()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}
void Selection(char l)
{
    if (l == 's' || l == 'S')
    {
        cout << "**********\n";
        PrintAllSmallLitters();
        cout << "**********";
    }
    else if (l == 'c' || l == 'C')
    {
        cout << "**********\n";
        PrintAllCapitalLitters();
        cout << "**********";
    }
    else
    {
        cout << "invalid selection";
        exit(1);
    }
}
int main()
{
    char litter;
    ReadData(litter);
    Selection(litter);
    return 0;
}