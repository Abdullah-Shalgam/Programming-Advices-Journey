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

void FillArrayWithColumnsSumOfMatrix(int Matrix[3][3], int Array[3], short Rows, short Columns)
{
    for (short j = 0; j < Rows; j++)
    {
        Array[j] = GetColumnSum(Matrix, j, Rows);
    } 
}

void PrintSumOfEachColumnInMatrix(int Array[3], short Columns)
{
    cout << "\nThe following are the sum of each column in the matrix:\n";
    for (short j = 0; j < Columns; j++)
    {
        printf(" Column %d Sum = %d\n", j + 1, Array[j]);
    }
}

int main()
{
    srand(time(0));
    int Matrix[3][3];
    int arrSum[3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    FillArrayWithColumnsSumOfMatrix(Matrix, arrSum, 3, 3);
    PrintSumOfEachColumnInMatrix(arrSum, 3);
    return 0;
}