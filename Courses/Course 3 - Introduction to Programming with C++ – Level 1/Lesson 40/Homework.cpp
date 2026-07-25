#include <iostream>
using namespace std;
void ReadData(float Numbers[3])
{
    cout << "Please Enter Grade1 : \n" , cin >> Numbers[0];
    cout << "Please Enter Grade2 : \n" , cin >> Numbers[1];
    cout << "Please Enter Grade3 : \n" , cin >> Numbers[2];
}
float Avg(float Numbers[3])
{
    return (Numbers[0] + Numbers[1] + Numbers[2]) / 3;
}
void PrintData(float Numbers[3] , float Average)
{
    cout << "*************************************************";
    cout << "\n The Average of Grades is : " << Average; 
    cout << "\n*************************************************";
}
int main()
{
    float Nums[3];
    ReadData(Nums);
    PrintData(Nums, Avg(Nums));
    return 0;
}