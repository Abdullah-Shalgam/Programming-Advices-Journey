#include <iostream>

using namespace std;

class clsA
{
private:
    //only accessible inside this class, neither derived classes
    //nor outside class.
    int _Var1;
    void _Fun1()
    {
        cout << "Function 1";
    }

protected:
    //only accessible inside this class and all derived classes,
    //but not outside class
    int Var2;
    void Fun2()
    {
        cout << "Function 2";
    }

public:
    // Accessible inside this class, all derived classes, and
    //outside class
    int Var3;
    void Fun3()
    {
        cout << "Function 3";
    }
};

class clsB : public clsA
{
public:
    void Func1()
    {
        cout << "Function 1 Derived.";
    }
};

int main()
{
    clsB B;
    B.Func1();
    return 0;
}