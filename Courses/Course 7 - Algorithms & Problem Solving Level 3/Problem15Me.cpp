#include <iostream>
#include <ctime>
#include <iomanip>
#include "MathLib.h"
#include "InputLib.h"

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

short GetNumberFrequencyInMatrix(int Matrix[3][3], short Rows, short Columns, short NumberToCount)
{
    short Frequency = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            if (Matrix[i][j] == NumberToCount)
            {
                Frequency++;
            }
        }
    }
    return Frequency;
}

int main()
{
    srand(time(0));
    //int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << endl;
    short NumberToCount  = InputLib::ReadIntNumber("Enter the number to count in matrix?: ");
    short NumberFrequency = GetNumberFrequencyInMatrix(Matrix, 3, 3, NumberToCount);
    printf("\nNumber %d count in matrix is %d", NumberToCount, NumberFrequency);
    return 0;
}