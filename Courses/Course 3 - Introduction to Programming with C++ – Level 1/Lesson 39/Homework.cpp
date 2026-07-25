#include <iostream>
using namespace std;
void ReadStudntsGrade()
{
    float studentgrades[3];
    cout << "Please Enter Grade1 : " , cin >> studentgrades[0];
    cout << "Please Enter Grade2 : " , cin >> studentgrades[1];
    cout << "Please Enter Grade3 : " , cin >> studentgrades[2];
    float Average = ((studentgrades[0] + studentgrades[1] + studentgrades[2])/3);
    cout << "*******************************************";
    cout << "\n The Average of Grades is : " << Average;
}
int main()
{
    ReadStudntsGrade();
    return 0;
}