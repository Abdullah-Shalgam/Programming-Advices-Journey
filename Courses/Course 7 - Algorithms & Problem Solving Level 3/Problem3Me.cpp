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

short GetRowSum(int Array[3][3], short RowNumber, short Column)
{
    short Sum = 0;
    for (short j = 0; j < Column; j++)
    {
        Sum += Array[RowNumber][j];
    }
    return Sum;
}

void FillArrayWithRowsSumOfMatrix(int Matrix[3][3], int Array[3], short Row, short Column)
{
    for (short i = 0; i < Row; i++)
    {
        Array[i] = GetRowSum(Matrix, i, Column);
    } 
}

void PrintSumOfEachRowInMatrix(int ArraySum[3], short Row)
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (short i = 0; i < Row; i++)
    {
        printf(" Row %d Sum = %d\n", i + 1, ArraySum[i]);
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
    FillArrayWithRowsSumOfMatrix(Matrix, arrSum, 3, 3);
    PrintSumOfEachRowInMatrix(arrSum, 3);
    return 0;
}