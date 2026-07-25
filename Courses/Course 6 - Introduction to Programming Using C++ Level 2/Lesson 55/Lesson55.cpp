#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void CreatFile()
{
    fstream Fill;
    Fill.open("MyNewFile.txt", ios::out | ios::app);
    if (Fill.is_open())
    {
        Fill << "Abdullah" << endl;
        Fill << "Siraj" << endl;
        Fill << "Mohammed" << endl;
        Fill << "Nizar" << endl;
        Fill << "Nori" << endl;
    }
    Fill.close();
}

void LoadFillContentToVector(string FillName, vector <string> & vFillComntet)
{
    fstream Fill;
    Fill.open(FillName, ios::in);
    if (Fill.is_open())
    {
        string Line;
        while(getline(Fill, Line))
        {
            vFillComntet.push_back(Line);
        }
    }
    Fill.close();
}

void PrintFillContent(string FillName)
{
    fstream Fill;
    Fill.open(FillName, ios::in);
    if (Fill.is_open())
    {
        string Line;
        while(getline(Fill, Line))
        {
            cout << Line << endl;
        }
    }
    Fill.close();
}
int main()
{
    CreatFile();
    cout << "File Content:\n\n";
    PrintFillContent("MyNewFile.txt");
    cout << "\n\nVector Content:\n\n";
    vector <string> vFillContent;
    LoadFillContentToVector("MyNewFile.txt", vFillContent);
    for (const string & Line : vFillContent)
    {
        cout << Line << endl;
    }
    return 0;
}