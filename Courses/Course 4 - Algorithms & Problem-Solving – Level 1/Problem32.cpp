#include <iostream>
using namespace std;

void ReadNumbers(int &Num, int &Power)
{
    cout << "Please Enter a number: ";
    cin >> Num;
    cout << "Please Enter the power: ";
    cin >> Power;
}

int NumberPowerofM(int Num, int Power)
{
    int Sum = 1;
    for (int i = 1; i <= Power; i++)
    {
        Sum *= Num;
    }
    return Sum;
}
void PrintPowerofM(int Num, int Power, int Sum)
{
    cout << "\n\n" << Num << " Power of "<< Power << " = " << Sum;
}
int main()
{
    int Num, Power;
    ReadNumbers(Num, Power);
    int PowerofM = NumberPowerofM(Num, Power);
    PrintPowerofM(Num, Power, PowerofM);
    return 0;
}