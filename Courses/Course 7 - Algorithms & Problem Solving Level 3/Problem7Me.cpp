#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(int Array[3][3], short Rows, short Columns)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            Counter++;
            Array[i][j] = Counter;
        }
    }
}

void PrintMatrixElements(int Array[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            cout << Array[i][j] << "     ";
        }
        cout << endl;
    }
}

void TransposeMatrix(int Matrix[3][3], int TransposedMatrix[3][3], short Rows, short Columns)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Columns; j++)
        {
            TransposedMatrix[j][i] = Matrix[i][j];
        }
    }
}

int main()
{
    int Matrix[3][3];
    int TransposedMatrix[3][3];
    FillMatrixWithOrderedNumbers(Matrix, 3, 3);
    cout << "The following is a 3x3 ordered matrix:\n";
    PrintMatrixElements(Matrix, 3, 3);
    TransposeMatrix(Matrix, TransposedMatrix, 3, 3);
    cout << "\nThe following is the transposed matrix:\n";
    PrintMatrixElements(TransposedMatrix, 3, 3);
    return 0;
}