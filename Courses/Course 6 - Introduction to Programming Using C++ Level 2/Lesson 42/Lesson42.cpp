#include <iostream>

using namespace std;

struct stEmplyee
{
    string Name;
    float Salary;
};
int main()
{
    void * ptr;
    stEmplyee Employee1;
    int x = 40;
    float y = 25.50;
    Employee1.Name = "Mohammed Abu-Hadhoud";
    Employee1.Salary = 5000;
    cout << ptr << endl;
    ptr = &Employee1;
    cout << &ptr << endl;
    cout << &(static_cast<stEmplyee*>(ptr))->Name << endl;
    cout << &(static_cast<stEmplyee*>(ptr))->Salary << endl;
    cout << (static_cast<stEmplyee*>(ptr)) << endl;
    cout << (static_cast<stEmplyee*>(ptr))->Name << endl;
    cout << (static_cast<stEmplyee*>(ptr))->Salary << endl;
    ptr = &x;
    cout << ptr << endl;
    cout << *(static_cast<int*>(ptr)) << endl;
    ptr = &y;
    cout << ptr <<endl;
    cout << *(static_cast<float*>(ptr));
    return 0;
}