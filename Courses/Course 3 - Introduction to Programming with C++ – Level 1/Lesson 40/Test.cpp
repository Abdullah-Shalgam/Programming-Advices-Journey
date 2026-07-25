#include <iostream>
using namespace std;
void ReadData(int Numbers[3])
{
    cout << "Please Enter the Number1 : \n" , cin >> Numbers[0];
    cout << "Please Enter the Number2 : \n" , cin >> Numbers[1];
    cout << "Please Enter the Number3 : \n" , cin >> Numbers[2];
}
void PrintData(int Numbers[3])
{
    cout << "*************************************************";
    cout << "\nNumber1 : " << Numbers[0];
    cout << "\nNumber2 : " << Numbers[1];
    cout << "\nNumber3 : " << Numbers[2];
    cout << "\n*************************************************";
}
int main()
{
    int Nums[3];
    ReadData(Nums);
    PrintData(Nums);
    return 0;
}