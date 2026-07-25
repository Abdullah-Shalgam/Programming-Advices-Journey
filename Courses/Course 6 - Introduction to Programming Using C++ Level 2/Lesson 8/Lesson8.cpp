#include <iostream>
#include "InputLib.h"

using namespace std;

int main()
{
    int Num = InputLib::ReadNumberInRange(10, 50, "Please enter number between (10 And 50): \n");
    cout << Num;
}
