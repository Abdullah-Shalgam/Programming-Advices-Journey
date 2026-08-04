#include <iostream>
#include <string>
using namespace std;
class clsA
{
    public:
        static int Fun1()
        {
            return 10;
        }
        
        int Fun2()
        {
            return 20;
        }
};

int main()
{
    clsA A1, A2;

    cout << clsA::Fun1() << endl;

    cout << A1.Fun1() << endl;
    cout << A1.Fun2() << endl;
    cout << A2.Fun1() << endl;
}