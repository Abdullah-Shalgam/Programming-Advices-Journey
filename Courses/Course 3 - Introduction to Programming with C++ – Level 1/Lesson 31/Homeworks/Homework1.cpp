#include <iostream>
#include <string>
using namespace std;
int main()
{
string string1 , string2 , string3;
cout << "Please enter string1:" << endl , getline(cin, string1);
cout << endl << "Pleases enter string2:" << endl , cin >> string2;
cout << endl << "Pleases enter string3:" << endl , cin >> string3;
cout << "***********************************************************" << endl;
cout << "The Length of string1 is: " << string1.length() << endl;
cout << "Characters at 0,2,4,7 are: " << string1[0] << "  " << string1[2] << "  " << string1[4] << "  " << string1[7] << endl;
string string4 = string2 + string3;
cout << "Concatonating string2 and string3 = " << string4 << endl;
int intstring = stoi(string2) * stoi(string3);
cout << "5 * 10 = " << intstring;
return 0;
}