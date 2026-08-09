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
            cout << setw(3);
            printf(" %d    ", Array[i][j]);
        }
        cout << endl;
    }
}

short GetMinimumNumberInMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short Min = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (Matrix[i][j] < Min)
                Min = Matrix[i][j];
        }
    }
    return Min;
}

short GetMaxNumbeInMatrix(int Matrix[3][3], short Rows, short Columns)
{
    short Max = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (Matrix[i][j] > Max)
                Max = Matrix[i][j];
        }
    }
    return Max;
}

int main()
{
    srand(time(0));
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << "\nMinimum Number is : " << GetMinimumNumberInMatrix(Matrix, 3 ,3);
    cout << "\n\nMax Number is : " << GetMaxNumbeInMatrix(Matrix, 3, 3);
    return 0;
}