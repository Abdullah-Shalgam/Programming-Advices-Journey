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

void CopyMatrix(int MatrixSource[3][3], int MatrixDestination[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            MatrixDestination[i][j] = MatrixSource[i][j];
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

short GetSumOfMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
        }
    }
    return true;
}

void PrintSparceOrNot(bool AreTypicalMatrices)
{
    if (AreTypicalMatrices)
        cout << "YES: both martices are typical.";
    else
        cout << "NO: martices are NOT typical.";
}

int main()
{
    srand(time(0));
    int Matrix1[3][3], Matrix2[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    //FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    CopyMatrix(Matrix1, Matrix2, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrixElements(Matrix2, 3, 3);
    cout << endl;
    PrintSparceOrNot(AreTypicalMatrices(Matrix1, Matrix2, 3, 3));
    return 0;
}