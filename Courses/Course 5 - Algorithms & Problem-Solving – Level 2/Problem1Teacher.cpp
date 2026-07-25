#include <iostream>
using namespace std;

void PrintTableHeader()
{
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}

string ColumnSperetor(int i)
{
    if (i != 10)
        return "   |";
    else
        return "  |";
}

void PrintMultiplicationTableFrom1ToN()
{
    PrintTableHeader();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumnSperetor(i);
        for (int j = 1; j <= 10; j++)
        {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
}

int main()
{
    PrintMultiplicationTableFrom1ToN();
    return 0;
}