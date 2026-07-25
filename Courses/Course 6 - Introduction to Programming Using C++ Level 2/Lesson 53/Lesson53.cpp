#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream File;
    File.open("MyFile.txt", ios::out | ios::app);
    if (File.is_open())
    {
        File << "This is a new line\n";
        File << "This is another new line\n";
    }
}