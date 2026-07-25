#include <iostream>
#include "InputLib.h"

using namespace std;

int main()
{
    int Num = InputLib::ReadIntNumber("Please enter how many students you want: ");
    float * pArrMark;
    pArrMark = new float[Num];
    for (short i = 0; i < Num; i++)
    {
        printf("\nEnter student %d Mark: ", i + 1);
        cin >> *(pArrMark + i);
    }
    cout << "\n\nAll Students Mark:-\n\n";
    for (short i = 0; i < Num; i++)
    {
        printf("Student %d Mark = %.3f\n", i + 1, *(pArrMark + i));
    }
    delete[] pArrMark;
    cout << "\n\n";
    return 0;
}