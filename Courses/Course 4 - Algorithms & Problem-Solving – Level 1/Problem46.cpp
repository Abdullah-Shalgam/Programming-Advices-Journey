#include <iostream>
using namespace std;

void PrintAllCapitalLetters()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}
int main()
{
    PrintAllCapitalLetters();
    return 0;
}