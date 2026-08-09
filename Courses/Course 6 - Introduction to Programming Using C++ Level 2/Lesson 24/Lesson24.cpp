#include <iostream>
#include "InputValidateLib.h"

using namespace std;

int main()
{
    const float PI = 3.1415927f;
    float R = InputValidateLib::ReadDblNumber("Enter the first numebr: \n");
    printf("PI = %.*f R = %.*f\n", 2, PI, 2, R);
    printf("PI = %.*f R = %.*f\n", 3, PI, 3, R);
    printf("PI = %.*f R = %.*f\n", 5, PI, 5, R);
    printf("PI = %.*f R = %.*f\n", 7, PI, 7, R);
    printf("%.4f / %.4f = %.4f\n", PI, R, PI / R);
}