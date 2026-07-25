#include <iostream>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num > 0)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Array [100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array [i] = RandomIntNumber(1, 100);
    }
}

void CopyArrayInReverseOrder (int ArraySource[100], int ArrayDestination[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        ArrayDestination [i] = ArraySource [ArrayLength - 1 - i];
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
    srand(time(0));
    const int MAX_SIZE = 100;
    int Array1[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    FillArrayWithRandomNumbers(Array1, ArrayLength);
    int Array2[MAX_SIZE];
    CopyArrayInReverseOrder(Array1, Array2, ArrayLength);
    cout << "\nArray 1 Elements: \n";
    PrintArrayElements(Array1, ArrayLength);
    cout << "\n\nArray 2 elements after copying array 1 in reversed order: \n";
    PrintArrayElements(Array2, ArrayLength);
    return 0;
}