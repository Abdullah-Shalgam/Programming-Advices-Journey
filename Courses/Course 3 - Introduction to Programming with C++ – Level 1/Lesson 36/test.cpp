#include <iostream>
using namespace std;
int L = 50;
int W = 30;
int Area = L*W;
int AreaFunction(int L = 50 , int W = 30)
{
    int Area = L * W;
    return Area;
}
int main()
{
    int L = 50 , W = 30;
    int Area = L*W;
    cout << "This is the Area Value from Local Function: " << Area << "\n";
    cout << "This is the Area Value from (AreaFuncion): " << AreaFunction() << "\n";
    cout << "This is the Area Value from Global: " << ::Area;
}