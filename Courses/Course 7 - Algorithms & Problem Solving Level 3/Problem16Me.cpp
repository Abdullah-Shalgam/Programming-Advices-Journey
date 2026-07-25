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

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short ZerosCounter = 0, OthersCounter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            (Matrix[i][j] == 0) ? ZerosCounter++ : OthersCounter++;
        }
    }
    return (ZerosCounter > OthersCounter);
}

void PrintSparceOrNot(bool IsSparceMatrix)
{
    if (IsSparceMatrix)
        cout << "YES: matrix is sparce.";
    else
        cout << "NO: matrix is NOT sparce.";
}

int main()
{
    srand(time(0));
    int Matrix[3][3] = { {9,0,7},{0,9,5},{0,12,9} };
    //int Matrix[3][3];
    //FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << endl;
    PrintSparceOrNot(IsSparceMatrix(Matrix, 3, 3));
    return 0;
}