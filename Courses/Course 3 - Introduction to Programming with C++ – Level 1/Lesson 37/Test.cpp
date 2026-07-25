#include <iostream>
using namespace std;
void prositour(int &Num)
{
    Num = 700;
    cout << "The value of Num inside the prositiour is : " << Num;
}
int main()
{
    int Num;
    Num = 2000;
    prositour(Num);
    cout << "Number after calling the fuction is : " << Num;
    return 0;
}