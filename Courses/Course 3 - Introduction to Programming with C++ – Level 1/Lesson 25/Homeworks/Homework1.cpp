#include <iostream>
using namespace std;
int main()
{
cout << (12 >= 12) << endl;
cout << (12 > 7) << endl;
cout << (8 < 6) << endl;
cout << (8 == 8) << endl;
cout << (12 <= 12) << endl;
cout << (7 == 5) << endl;
cout << !(12 >= 12) << endl;
cout << !(12 > 7) << endl;
cout << !(8 < 6) << endl;
cout << !(8 == 8) << endl;
cout << !(12 <= 12) << endl;
cout << !(7 == 5) << endl;
cout << (1 && 1) << endl;
cout << (true && false) << endl;
cout << (0 || 1) << endl;
cout << (0 || 0) << endl;
cout << !(0) << endl;
cout << !(1 || 0) << endl;
cout << ((7 == 7) && (7 > 5)) << endl;
cout << ((7 == 7) && (7 < 5)) << endl;
cout << ((7 == 7) || (7 < 5)) << endl;
cout << ((7 < 7) || (7 > 5)) << endl;
cout << !((7 == 7) && (7 > 5)) << endl;
cout << ((7 == 7) && !(7 < 5));
return 0;
}