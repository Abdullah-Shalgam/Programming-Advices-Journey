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
            Array[i][j] = MathLib::RandomNumber(1, 100);
        }
    }
}

void PrintMatrixElements(int Array[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            cout << setw(3) << Array[i][j] << "\t";
        }
        cout << endl;
    }
}

short GetColumnSum(int Array[3][3], short ColumnNumber, short Rows)
{
    short Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += Array[i][ColumnNumber];
    }
    return Sum;
}

void PrintSumOfEachColumnInMatrix(int Array[3][3], short Rows, short Columns)
{
    cout << "\nThe following are the sum of each column in the matrix:\n";
    for (short j = 0; j < Columns; j++)
    {
        printf(" Column %d Sum = %d\n", j + 1, GetColumnSum(Array, j, Rows));
    }
}

int main()
{
    srand(time(0));
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    PrintSumOfEachColumnInMatrix(Matrix, 3, 3);
    return 0;
}