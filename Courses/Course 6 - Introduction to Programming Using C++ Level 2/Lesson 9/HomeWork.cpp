#include <iostream>
#include "InputLib.h"

enum enP_N_Z {Positive = 1, Negative = 2, Zero = 3};

using namespace std;

enP_N_Z PositiveOrNegativeNumber(int Num)
{
    return (Num > 0) ? enP_N_Z::Positive : enP_N_Z::Negative;
}

enP_N_Z PositiveOrNegativeOrZero(int Num)
{
    return (Num == 0) ? enP_N_Z::Zero : ((Num > 0) ? enP_N_Z::Positive : enP_N_Z::Negative);
}

string P_N_Z_ToString(enP_N_Z PNZ)
{
    string Arr[3] = {"Positive", "Negative", "Zero"};
    return Arr[PNZ - 1];
}

int main()
{
    cout << P_N_Z_ToString(PositiveOrNegativeNumber(InputLib::ReadNumber("Please enter a number: \n")));
    cout << endl;
    cout << P_N_Z_ToString(PositiveOrNegativeOrZero(InputLib::ReadNumber("Please enter a number: \n")));
    return 0;
}