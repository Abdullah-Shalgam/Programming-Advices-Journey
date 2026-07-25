#include <iostream>
#include <string>
using namespace std;
int main()
{
int Num1;
float Num2 = 16.42;
Num1 = Num2;
Num1 = int(Num2);
Num1 = (int) Num2;
cout << Num1 << endl << Num2;
string str = "145.5645493453453453";
int int_num = stoi(str);
float float_num = stof(str);
double double_num = stod(str);
cout << "\n\n\n\n" << int_num << endl << float_num << endl << double_num;
string S1 , S2;
S1 = to_string(Num1);
S2 = to_string(Num2);
cout << "\n\n\n\n" << S1 << endl << S2;
return 0;
}