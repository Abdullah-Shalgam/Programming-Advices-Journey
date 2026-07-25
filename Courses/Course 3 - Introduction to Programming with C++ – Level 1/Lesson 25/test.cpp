#include <iostream>
using namespace std;
int main()
{
bool A = 1 , B = 0;
cout << (A&&B) << endl;
cout << (A||B) << endl;
cout << (!A) << endl;
cout << (!B) << endl;
cout << (!(A&&B)) << endl;
cout << (!(A||B)) << endl;
return 0;
}