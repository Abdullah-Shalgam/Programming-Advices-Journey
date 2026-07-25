#include <iostream>
#include <fstream>

using namespace std;

void CreatFile()
{
    fstream File;
    File.open("MyNewFile.txt", ios::out | ios::app);
    if (File.is_open())
    {
        File << "Abdullah" << endl;
        File << "Siraj" << endl;
        File << "Mohammed" << endl;
        File << "Nizar" << endl;
        File << "Nori" << endl;
    }
}

void PrintFillContent(string FillName)
{
    fstream File;
    File.open(FillName, ios::in);
    if (File.is_open())
    {
        string Line;
        while(getline(File, Line))
        {
            cout << Line << endl;
        }
    }
}
int main()
{
    CreatFile();
    PrintFillContent("MyNewFile.txt");
    return 0;
}