#include <iostream>
using namespace std;
int main()
{
float M1 , M2 , M3;
cout << "Please Enter the first Mark: " << endl , cin >> M1;
cout << "Please Enter the second Mark: " << endl , cin >> M2;
cout << "Please Enter the third Mark: " << endl , cin >> M3;
float Avg = (M1+M2+M3)/3;
cout << endl << Avg;
return 0;
}