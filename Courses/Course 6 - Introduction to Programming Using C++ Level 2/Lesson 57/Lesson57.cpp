#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void CreatFile()
{
    fstream File;
    File.open("MyNewFile.txt", ios::out);
    if (File.is_open())
    {
        File << "Abdullah" << endl;
        File << "Siraj" << endl;
        File << "Mohammed" << endl;
        File << "Nizar" << endl;
        File << "Nori" << endl;
        File << "Faroq" << endl;
    }
    File.close();
}

void LoadFillContentToVector(string FillName, vector <string> & vFillComntet)
{
    fstream File;
    File.open(FillName, ios::in);
    if (File.is_open())
    {
        string Line;
        while(getline(File, Line))
        {
            if (Line != "")
                vFillComntet.push_back(Line);
        }
    }
    File.close();
}

void LoadDataFromVectorToFile(string FillName, vector <string> vFillContent)
{
    fstream File;
    File.open(FillName, ios::out);
    if (File.is_open())
    {
        for (const string & Line : vFillContent)
        {
            if (Line != "")
                File << Line << endl;
        }
    }
    File.close();
}

void DeleteRecordFromFill(string FillName, string DeleteRecord)
{
    bool IsFound = false;
    vector <string> vFillContent;
    LoadFillContentToVector(FillName, vFillContent);
    for (string & Line : vFillContent)
    {
        if (Line == DeleteRecord)
        {
            Line = "";
            IsFound = true;
        }
    }
    LoadDataFromVectorToFile(FillName, vFillContent);
    if (!IsFound)
        cout << "Delete is Failed.\nSorry We couldn't find " << DeleteRecord << " in that file.";
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
    File.close();
}
int main()
{
    CreatFile();
    cout << "File Content before Update:\n\n";
    PrintFillContent("MyNewFile.txt");
    DeleteRecordFromFill("MyNewFile.txt", "Nizar");
    cout << "\n\nFile Content After Update:\n\n";
    PrintFillContent("MyNewFile.txt");
    return 0;
}