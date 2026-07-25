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

void PrintMiddleRowOfMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short MiddleRow = Rows / 2;
    for (short j = 0; j < Columns; j++)
    {
        cout << setw(3);
        printf(" %0.*d    ", 2, Matrix[MiddleRow][j]);
    }
}

void PrintMiddleColumnOfMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short MiddleColumn = Columns / 2;
    for (short i = 0; i < Rows; i++)
    {
        cout << setw(3);
        printf(" %0.*d    ", 2, Matrix[i][MiddleColumn]);
    }
}

int main()
{
    srand(time(0));
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << "\nMiddle Row of Matrix is:\n";
    PrintMiddleRowOfMatrix(Matrix, 3, 3);
    cout << "\nMiddle Column of Matrix is:\n";
    PrintMiddleColumnOfMatrix(Matrix, 3, 3);
    return 0;
}