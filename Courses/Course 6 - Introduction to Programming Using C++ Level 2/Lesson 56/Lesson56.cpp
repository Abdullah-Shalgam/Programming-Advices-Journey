#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void LoadDataFromVectorToFile(string FillName, vector <string> vFillContent)
{
    fstream Fill;
    Fill.open(FillName, ios::out);
    if (Fill.is_open())
    {
        for (const string & Line : vFillContent)
        {
            Fill << Line << endl;
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
    vector <string> vFillContent;
    for (short i = 1; i <= 10; i++)
    {
        vFillContent.push_back("Hello World");
    }
    LoadDataFromVectorToFile("MyNewFile.txt", vFillContent);
    cout << "File Content:\n\n";
    PrintFillContent("MyNewFile.txt");
    return 0;
}