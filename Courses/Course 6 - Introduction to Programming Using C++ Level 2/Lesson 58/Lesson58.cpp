#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void CreatFile()
{
    fstream Fill;
    Fill.open("MyNewFile.txt", ios::out);
    if (Fill.is_open())
    {
        Fill << "Abdullah" << endl;
        Fill << "Siraj" << endl;
        Fill << "Mohammed" << endl;
        Fill << "Nizar" << endl;
        Fill << "Nori" << endl;
        Fill << "Faroq" << endl;
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
            if (Line != "")
                vFillComntet.push_back(Line);
        }
    }
    Fill.close();
}

void LoadDataFromVectorToFile(string FillName, vector <string> vFillContent)
{
    fstream Fill;
    Fill.open(FillName, ios::out);
    if (Fill.is_open())
    {
        for (const string & Line : vFillContent)
        {
            if (Line != "")
                Fill << Line << endl;
        }
    }
    Fill.close();
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

void UpdateRecordFromFill(string FillName, string DeleteRecord, string UpdateRecord)
{
    bool IsFound = false;
    vector <string> vFillContent;
    LoadFillContentToVector(FillName, vFillContent);
    for (string & Line : vFillContent)
    {
        if (Line == DeleteRecord)
        {
            Line = UpdateRecord;
            IsFound = true;
        }
    }
    LoadDataFromVectorToFile(FillName, vFillContent);
    if (!IsFound)
        cout << "Update is Failed.\nSorry We couldn't find " << DeleteRecord << " in that file.";
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
    cout << "File Content before Update:\n\n";
    PrintFillContent("MyNewFile.txt");
    DeleteRecordFromFill("MyNewFile.txt", "Nizar");
    cout << "\n\nFile Content After Delete Record:\n\n";
    PrintFillContent("MyNewFile.txt");
    UpdateRecordFromFill("MyNewFile.txt", "Nori", "Khalid");
    cout << "\n\nFile Content After Update Record:\n\n";
    PrintFillContent("MyNewFile.txt");
    return 0;
}