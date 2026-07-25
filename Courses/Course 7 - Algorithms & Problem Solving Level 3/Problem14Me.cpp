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

void PrintMatrixElements(int Array[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            cout << setw(3);
            printf(" %0.*d    ", 2, Array[i][j]);
        }
        cout << endl;
    }
}

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short FirstDiagonalElement = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (i == j)
            {
                if (Matrix[i][j] != FirstDiagonalElement) 
                    return false;
            }
            else
            {
                if (Matrix[i][j] != 0) 
                    return false;
            }
        }
    }
    return true;
}

void PrintSparceOrNot(bool IsScalarMatrix)
{
    if (IsScalarMatrix)
        cout << "YES: matrix is scalar.";
    else
        cout << "NO: matrix is NOT scalar.";
}

int main()
{
    srand(time(0));
    int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
    //int Matrix[3][3];
    //FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << endl;
    PrintSparceOrNot(IsScalarMatrix(Matrix, 3, 3));
    return 0;
}