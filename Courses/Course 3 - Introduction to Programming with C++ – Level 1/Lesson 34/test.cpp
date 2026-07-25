#include <iostream>
using namespace std;
void MyProcedure()
{
     cout << "This is my first Procedure, it got executed :-)" << endl;
}
string Myfunction()
{
    return "This is my first returning value Function, This is the value";
}
int main()
{
    MyProcedure();
    cout << Myfuction() << endl;
    return 0;
}