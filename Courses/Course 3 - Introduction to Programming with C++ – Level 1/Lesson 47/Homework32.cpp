#include <iostream>
#include <cstdlib>
using namespace std;
void ReadData(int &Num , int &Power)
{
    cout << "Please Enter a Number : \n";
    cin >> Num;
    cout << "Please Enter the Power : \n";
    cin >> Power;
    if (Num == 0)
    {
        cout << "Your Entered zero.";
        exit(1);
    }
    if (Power == 0)
    {
        cout << Num << " Power of " << Power << " = " << 1;
        exit(0);
    }

}
int PowerofNumber(int Num , int Power)
{
    int defultNum = Num;
    for (int i = 1; i < Power; i++)
    {
        Num = Num * defultNum;
    }
    return Num;
}
int main()
{
    int Number , P;
    ReadData(Number , P);
    cout << Number << " Power of " << P << " = " << PowerofNumber(Number , P);
    return 0;
}