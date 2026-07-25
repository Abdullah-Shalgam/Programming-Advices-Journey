#include <iostream>
#include <ctime>
#include <iomanip>
#include "MathLib.h"

using namespace std;

void FillMatrixWithRandomNumbers(int Array[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            Array[i][j] = MathLib::RandomNumber(1, 10);
        }
    }
}

void MultiplyTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], int MultiplyMatrix[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            MultiplyMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

void PrintMatrixElements(int Array[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            cout << setw(3);
            printf(" %0.*d     ", 2, Array[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int Matrix1[3][3], Matrix2[3][3], MultiplyMatrix[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    MultiplyTwoMatrix(Matrix1, Matrix2, MultiplyMatrix, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrixElements(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrixElements(Matrix2, 3, 3);
    cout << "\nResults:\n";
    PrintMatrixElements(MultiplyMatrix, 3, 3);
    return 0;
}