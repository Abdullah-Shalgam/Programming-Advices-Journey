#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Please Enter a Number: ";
    cin >> Number;
    return Number;
}

float HalfNumber(int Num)
{
    return (float)Num/2;
}

void PrintHalfNumber(int Num)
{
    string Result = "";
    Result = "The Half of Number " + to_string(Num) + " is: " + to_string(HalfNumber(Num));
    cout << endl << Result;
}

int main()
{
    PrintHalfNumber(ReadNumber());
    return 0;
}