#include <iostream>
using namespace std;

void ReadNumber(int &Num)
{
    cout << "Please Enter a Number: ";
    cin >> Num;
}

void SwapNumbers(int &Num1, int &Num2)
{
    int Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void PrintSwapNumbers(int Num1, int Num2)
{
    cout << "\n\nNumber 1 is: " << Num1;
    cout << "\nNumber 2 is: " << Num2;
}

int main()
{
    int Num1 , Num2;
    ReadNumber(Num1);
    ReadNumber(Num2);
    PrintSwapNumbers(Num1, Num2);
    SwapNumbers(Num1, Num2);
    PrintSwapNumbers(Num1, Num2);
    return 0;
}