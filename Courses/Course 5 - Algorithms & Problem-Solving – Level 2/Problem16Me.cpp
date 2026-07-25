#include <iostream>
using namespace std;

void PrintAllWordsFromAAAToZZZ()
{
    cout << "All words from AAA to ZZZ: \n";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int f = 65; f <= 90; f++)
            {
                cout << char(i);
                cout << char(j);
                cout << char(f);
                cout << "\n";
            }
        }
    }
    cout << "________________________________________";
}

int main()
{
    PrintAllWordsFromAAAToZZZ();
    return 0;
}