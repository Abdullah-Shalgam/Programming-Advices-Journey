#include <iostream>

using namespace std;

void Function1(int &x)
{
    x++;
}
int main()
{
    int a = 10;
    Function1(a);
    cout << "a after calling function1 = " << a << endl;
    cout << "a and x adress = " << &a;
    return 0;
}