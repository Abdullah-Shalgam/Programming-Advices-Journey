#include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

int ReadMark()
{
    int Mark;
    cout << "Please Enter your Mark: ";
    cin >> Mark;
    return Mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintPassORFailed(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\nYou passed";
    else
        cout << "\nYou Faild";
}

int main()
{
    PrintPassORFailed(ReadMark());
    return 0;
}