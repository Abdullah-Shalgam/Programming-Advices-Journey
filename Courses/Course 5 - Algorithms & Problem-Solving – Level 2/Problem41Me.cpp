#include <iostream>
#include <ctime>
using namespace std;

void FillArrayWithPredefinedNumbers(int Array[100], int &ArrayLength)
{
    ArrayLength = 6;
    
    Array[0] = 10; 
    Array[1] = 20; 
    Array[2] = 30; 
    Array[3] = 30; 
    Array[4] = 20; 
    Array[5] = 10;
}

bool IsPalindromeArray(int Array[100], int ArrayLength)
{
    int Counter = ArrayLength - 1;
    for (int i = 0; i < ArrayLength / 2; i++)
    {
        if (Array[i] != Array[Counter])
            return false;
        Counter--;
    }
    return true;
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
    int Array[MAX_SIZE] , ArrayLength = 0;
    FillArrayWithPredefinedNumbers(Array, ArrayLength);
    cout << "\nArray 1 Elements:\n";
    PrintArrayElements(Array, ArrayLength);
    if(IsPalindromeArray(Array, ArrayLength))
        cout << "\n\nYes, Array is palindrome.";
    else
        cout << "\n\nNo, Array is not palindrome.";
    return 0;
}