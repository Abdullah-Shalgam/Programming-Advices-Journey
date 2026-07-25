#include <iostream>
using namespace std;

int ReadNumber()
{
    int Num;
    cout << "Please Enter a number: ";
    cin >> Num;
    return Num;
}

void PrintPower2_3_4(int Num)
{
    cout << "\n\n" << Num << " Power of 2 = " << Num*Num;
    cout << "\n" << Num << " Power of 3 = " << Num*Num*Num;
    cout << "\n" << Num << " Power of 4 = " << Num*Num*Num*Num;
}
int main()
{
    PrintPower2_3_4(ReadNumber());
    return 0;
}