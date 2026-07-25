#include <iostream>
#include <cstdlib>
using namespace std;

void ReadData(int &Num , int &Power)
{
    cout << "Please Enter a Number : \n";
    cin >> Num;
    cout << "Please Enter the Power : \n";
    cin >> Power;
    if (Power == 0)
    {
        cout << Num << " Power of " << Power << " = " << 1;
        exit(0);
    }

}
int PowerofNumber(int Num , int Power)
{
    int defultNum = Num;
    int i = 1;
    while (Power > i)
    {
        Num = Num * defultNum;
        i++;
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