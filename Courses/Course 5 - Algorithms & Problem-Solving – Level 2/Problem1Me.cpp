#include <iostream>
#include <string>
using namespace std;

void PrintTheTitle()
{
    cout << "\n\n                                    Multiplication Table From 1 to 10\n\n";
}

void PrintColumnNumbers()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "          " << i;
    }
}

void PrintColumn()
{
    cout << "\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "____________";
    }
}
void PrintRow(int i)
{
    if (i != 10)
        cout << i << "    |    " << i;
    else
        cout << i << "   |   " << i;
    for (int j = 2; j <= 10; j++)
    {
        string Textij = to_string(i * j);
        if (Textij.length() == 1)
        {
            cout << "          ";
            cout << Textij;
        }
        else
        {
            cout << "         ";
            cout << Textij;
        }
    }
}

void PrintTheTableContains()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << endl;
        PrintRow(i);
    }
}

void PrintMultiPlicationTableFrom1to10()
{
    PrintTheTitle();
    PrintColumnNumbers();
    PrintColumn();
    PrintTheTableContains();
}
int main()
{
    PrintMultiPlicationTableFrom1to10();
    return 0;
}