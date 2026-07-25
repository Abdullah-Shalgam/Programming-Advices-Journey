#include <iostream>

using namespace std;

int main()
{
    string Arr[4] = {"Hello", "And", "Welcome", "Home"};
    for (string Word : Arr)
    {
        cout << Word << " ";
    }
    return 0;
}