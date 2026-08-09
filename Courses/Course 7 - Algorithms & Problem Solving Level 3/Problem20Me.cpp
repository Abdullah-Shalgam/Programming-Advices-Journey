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

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Columns - 1 - j])
                return false;
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    //int Matrix[3][3];
    //FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    cout << endl;
    if (IsPalindromeMatrix(Matrix, 3, 3))
        cout << "Yes: Matrix is Palindrome.";
    else
        cout <<"No: Matrix is NOT Palindrome.";
    return 0;
}