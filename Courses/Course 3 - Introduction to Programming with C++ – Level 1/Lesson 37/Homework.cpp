#include <iostream>
using namespace std;
void Swap(int &N1 , int &N2)
{
    int temp = N1;
    N1 = N2;
    N2 = temp;
    cout << "After swap Num1 in prosetior = " << N1 << " And Num2 = " << N2 << endl;
}
int main()
{
    int Num1 , Num2;
    cout << "Please Enter the value of Num1 : " , cin >> Num1;
    cout << "Please Enter the value of Num2 : " , cin >> Num2;
    cout << "Before swap Num1 = " << Num1 << " And Num2 = " << Num2 << endl;
    Swap(Num1 , Num2);
    cout << "After swap Num1 in main = " << Num1 << " And Num2 = " << Num2;
    return 0;
}