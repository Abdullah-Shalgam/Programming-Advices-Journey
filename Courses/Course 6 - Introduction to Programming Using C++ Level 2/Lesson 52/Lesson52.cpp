#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream NewFile;
    NewFile.open("Koko.txt", ios::out);
    if (NewFile.is_open())
    {
        for (short i = 1; i <= 1000; i++)
        {
            NewFile << "Hello!\n";
        }
        NewFile.close();
    }
}