#include <iostream>

using namespace std;

void Swap(int * n1, int * n2)
{
    int Temp = *n1;
    *n1 = *n2;
    *n2 = Temp;
}

int main()
{
    int a = 30, b = 50;
    cout << "A and B value before swap:-\n";
    cout << "a = " << a;
    cout << "\nb = " << b;
    Swap(&a, &b);
    cout << "\nA and B value after swap:-\n";
    cout << "a = " << a;
    cout << "\nb = " << b;
}