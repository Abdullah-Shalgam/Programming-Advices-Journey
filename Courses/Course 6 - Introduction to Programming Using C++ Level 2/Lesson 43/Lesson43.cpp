#include <iostream>

using namespace std;

int main()
{
    void * PtrX;
    float * PtrY;
    PtrX = new int;
    PtrY = new float;
    *(static_cast<int*>(PtrX)) = 40;
    *PtrY = 23.62;
    cout << *(static_cast<int*>(PtrX)) << endl;
    cout << *PtrY << endl;
    delete (static_cast<int*>(PtrX));
    delete PtrY;
    return 0;
}