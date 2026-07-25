#include <iostream>
using namespace std;

void ReadData(char &l)
{
    cout << "Do you want to print all small or capital litters (S/C) : \n";
    cin >> l;
}
void PrintAllSmallLitters()
{
    int i = 97;
    while (i <= 122)
    {
        cout << char(i) << endl;
        i++;
    }
}
void PrintAllCapitalLitters()
{
    int i = 65;
    while (i <= 90)
    {
        cout << char(i) << endl;
        i++;
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