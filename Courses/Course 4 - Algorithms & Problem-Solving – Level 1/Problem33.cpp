#include <iostream>
using namespace std;

int ReadNumberInRange(int From, int to)
{
    int Mark;
    do
    {
        cout << "Please enter your mark between 0 and 100: ";
        cin >> Mark;
        if (Mark >= From && Mark <= to)
            return Mark;
        cout << "Invalid Mark!";
    } while (true);
}

char GetGradeLetter(int Mark)
{
    if (Mark >= 90)
        return 'A';
    else if (Mark >= 80)
        return 'B';
    else if (Mark >= 70)
        return 'C';
    else if (Mark >= 60)
        return 'D';
    else if (Mark >= 50)
        return 'E';
    else
        return 'F';
}

void PrintGrade(char Grade)
{
    cout << "\nYour Grade is: " << Grade;
}
int main()
{
    PrintGrade(GetGradeLetter(ReadNumberInRange(0, 100)));
    return 0;
}