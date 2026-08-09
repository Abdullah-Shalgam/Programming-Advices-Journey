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
    int Matrix[3][3] = { {9,0,7},{0,0,5},{0,0,0} };
    //int Matrix[3][3];
    //FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << endl;
    short NumToCheck = InputValidateLib::ReadIntNumber("Please Enter the number to lock for in matrix?: ");
    cout << endl;
    PrintEsistOrNot(IsNumberExistInMatrix(Matrix, 3, 3, NumToCheck));
    return 0;
}