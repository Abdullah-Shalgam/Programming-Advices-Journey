#include <iostream>
#include "InputValidateLib.h"

using namespace std;

int main()
{
    int Num = InputValidateLib::ReadNumberInRange(10, 50, "Please enter number between (10 And 50): \n");
    cout << Num;
}
