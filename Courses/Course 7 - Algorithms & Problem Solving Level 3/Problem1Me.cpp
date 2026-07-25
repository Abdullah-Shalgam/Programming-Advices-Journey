#include <iostream>
#include <ctime>
#include <iomanip>
#include "MathLib.h"

using namespace std;

void FillMatrixWithRandomNumbers(int Array[3][3], short Row, short Column)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Column; j++)
        {
            Array[i][j] = MathLib::RandomNumber(1, 100);
        }
    }
}

void PrintMatrixElements(int Array[3][3], short Row, short Column)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Column; j++)
        {
            cout << setw(3) << Array[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << " The following is a 3x3 random matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    return 0;
}