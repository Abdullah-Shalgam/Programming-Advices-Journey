#include <iostream>
using namespace std;
void ReadMarks(float Marks[3])
{
    cout << "Please Enter Mark1 : \n";
    cin >> Marks[0];
    cout << "Please Enter Mark2 : \n";
    cin >> Marks[1];
    cout << "Please Enter Mark3 : \n";
    cin >> Marks[2];
}
int main()
{
    float m[3];
    ReadMarks(m);
    float Avg;
    Avg = (m[0] + m[1] + m[2])/3;
    if (Avg >= 50)
    {
        cout << Avg << endl;
        cout << "PASS";
    }
    else
    {
        cout << Avg << endl;
        cout << "FAIL";
    }
    return 0;
}