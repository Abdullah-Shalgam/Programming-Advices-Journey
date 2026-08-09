#include <iostream>
#include <ctime>
#include <iomanip>
#include "InputValidateLib.h"
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

bool IsNumberExistInMatrix(int Matrix[3][3], short Rows, short Columns, short NumberToCheck)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (Matrix[i][j] == NumberToCheck)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (IsNumberExistInMatrix(Matrix2, Rows, Columns, Matrix1[i][j]))
                cout << setw(3) << Matrix1[i][j] << "\t";
        }
    }
}

void PrintEsistOrNot(bool IsNumberExistInMatrix)
{
    if (IsNumberExistInMatrix)
        cout << "YES: it is there.";
    else
        cout << "NO: it is NOT there.";
}

int main()
{
    srand(time(0));
    int Matrix1[3][3], Matrix2[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrixElements(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrixElements(Matrix2, 3, 3);
    cout << "\nIntersected Numbers are:\n\n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);
    return 0;
}