#include <iostream>
#include <ctime>
using namespace std;

void AddArrayElement(int Number, int Array [100], int &ArrayLength)
{
    Array[ArrayLength] = Number;
    ArrayLength++;
}

void FillArrayWithPredefinedNumbers(int Array[100], int &ArrayLength)
{
    ArrayLength = 10;
    
    Array[0] = 10; 
    Array[1] = 10; 
    Array[2] = 10; 
    Array[3] = 50; 
    Array[4] = 50; 
    Array[5] = 70; 
    Array[6] = 70; 
    Array[7] = 70; 
    Array[8] = 70; 
    Array[9] = 90;
}

short FindNumberPositionInArray (int Array [100], int ArrayLength, int NumberToCheck)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array [i] == NumberToCheck)
        {
            return i;
        }
    }
    return -1;
}

bool IsNumberInArray(int Array [100], int ArrayLength, int NumberToCheck)
{
    return FindNumberPositionInArray(Array, ArrayLength, NumberToCheck) != -1;
}

void CopyDistinctNumbersFromArray (int ArraySource[100], int ArrayDestination[100], int ArraySourceLength, int &ArrayDestinationLength)
{
    for (int i = 0; i < ArraySourceLength; i++)
    {
        if (!IsNumberInArray(ArrayDestination, ArrayDestinationLength, ArraySource[i]))
            AddArrayElement(ArraySource[i], ArrayDestination, ArrayDestinationLength);
    }
}

void PrintArrayElements(int Array [100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength;i++)
    {
        cout << Array [i] << " ";
    }
}

int main()
{
    const int MAX_SIZE = 100;
    int Array1[MAX_SIZE] , Array1Length = 0, Array2[MAX_SIZE], Array2Length = 0;
    FillArrayWithPredefinedNumbers(Array1, Array1Length);
    CopyDistinctNumbersFromArray(Array1, Array2, Array1Length, Array2Length);
    cout << "\nArray 1 Elements:\n";
    PrintArrayElements(Array1, Array1Length);
    cout << "\n\nArray 2 Distinct Elements:\n";
    PrintArrayElements(Array2, Array2Length);
    return 0;
}