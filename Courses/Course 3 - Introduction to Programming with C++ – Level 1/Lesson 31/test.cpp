#include <iostream>
#include <string>
using namespace std;
int main()
{
string Mystring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
cout << "The length of Mystring is: " << Mystring.length() << endl;
cout << Mystring[5] << endl;
string S1 = "10" , S2 = "20";
string S3 = S1 + S2;
cout << S3 << endl;
int Sum = stoi(S1) + stoi(S2);
cout << Sum << endl;
string Fullname;
//cin >> Fullname;
getline(cin, Fullname);
cout << Fullname;
return 0;
}