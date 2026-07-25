#include <iostream>
#include <vector>

using namespace std;

void ReadNumbersUntelSayNo(vector <int> & vNums)
{
    int UserNum = 0;
    char Answer = 'y';
    do
    {
        cout << "Enter the Number: \n";
        cin >> UserNum;
        vNums.push_back(UserNum);
        cout << "Number Added successfully\n\n";
        cout << "do you want to add another number [Y/N]: \n";
        cin >> Answer;
        cout << endl;
    } while (Answer == 'y' || Answer == 'Y');
}

void PrintVectorElements(const vector <int> & vNums)
{
    cout << "Numbers Added:\n\n";
    for (const int & Num : vNums)
    {
        cout << Num << "\n";
    }
    cout << endl;
}

int main()
{
    vector <int> vNums;
    ReadNumbersUntelSayNo(vNums);
    PrintVectorElements(vNums);
}