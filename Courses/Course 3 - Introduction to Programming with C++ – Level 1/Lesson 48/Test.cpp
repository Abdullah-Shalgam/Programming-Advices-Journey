#include <iostream>
#include <cstdlib>
using namespace std;
void ReadNumbers(int Arra[100] , int &Length)
{
    cout << "How many Numbers do you want to enter? 1 to 100 : \n";
    cin >> Length;
    if (Length >= 1 && Length <= 100)
    {
        for (int i = 0; i < Length; i++)
        {
            cout << "Enter the Number " << i+1 << " : \n";
            cin >> Arra[i];
        }
    }
    else
    {
        cout << "Invalid Selection";
        exit(1);
    }
}
void PrintNumbers(int Arra[100] , int Length)
{
    cout << "*******************************\n";
    for (int i = 0; i < Length; i++)
    {
        cout << "Number " << "[" << i+1 << "] : " << Arra[i] << endl;
    }
    cout << "*******************************\n";
}
int SumNumbers(int Arra[100] , int Length)
{
    int Sum = 0;
    for (int i = 0; i < Length; i++)
    {
        Sum = Sum + Arra[i];
    }
    return Sum;
}
float AvgNumbers(int Sum , int Length)
{
    return (float) Sum/Length;
}
int main()
{
    int Array[100] , Length , Sum;
    ReadNumbers(Array, Length);
    PrintNumbers(Array, Length);
    cout << "*******************************\n";
    Sum = SumNumbers(Array , Length);
    cout << "Sum : " << Sum;
    cout << "\nAvg : " << AvgNumbers(Sum , Length);
    return 0;
}