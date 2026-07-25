#include<iostream>
using namespace std;

int main()
{
    int Mark = 90;
    string result;
    //Using norma if
    if (Mark >= 50)
    {
    result = "PASS";
    }
    else
    {
    result = "FAIL";
    }
    cout << result << endl;
    //Using Short Hand IF
    result = (Mark >= 50) ? "PASS" : "FAIL";
    cout << result << endl;
    return 0;
}