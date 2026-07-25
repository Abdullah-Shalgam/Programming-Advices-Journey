#include <iostream>
#include <string>
using namespace std;
int main()
{
string st1 = "43.22";
int int1;
int1 = stoi(st1);
float float1;
float1 = stof(st1);
double double1;
double1 = stod(st1);
cout << st1 << endl << int1 << endl << float1 << endl << double1;
int N1 = 20;
string str_N1 = to_string(N1);
double N2 = 33.50;
string str_N2 = to_string(N2);
float N3 = 55.23;
string  str_N3 = to_string(N3);
int int_N3 = N3;
int_N3 = (int) N3;
int_N3 = int(N3);
cout << "\n\n\n\n" << str_N1 << endl << str_N2 << endl << str_N3 << endl << int_N3;
return 0;
}