#include <iostream>
#include "InputLib.h"

using namespace std;

int main()
{
    int Num1 = InputLib::ReadIntNumber("Enter the first number: \n");
    int Num2 = InputLib::ReadIntNumber("Enter the second number: \n");
    int Sum = Num1 + Num2;
    printf("\nFirst Number = %d \n", Num1);
    printf("Second Number = %d \n", Num2);
    printf("Number 1 = %0*d\n", 6, Num1);
    printf("Number 2 = %0*d\n", 6, Num2);
    printf("%d + %d = %d", Num1, Num2, Sum);
}