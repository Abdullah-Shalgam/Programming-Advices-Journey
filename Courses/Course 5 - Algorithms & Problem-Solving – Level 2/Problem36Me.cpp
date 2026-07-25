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

void AddArrayElement(int Number, int Array [100], int &ArrayLength)
{
    Array[ArrayLength] = Number;
    ArrayLength++;
}

void CopyArray (int ArraySource[100], int ArrayDestination[100], int ArraySourceLength, int &ArrayDestinationLength)
{
    for (int i = 0; i < ArraySourceLength; i++)
    {
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
    srand(time(0));
    const int MAX_SIZE = 100;
    int Array1[MAX_SIZE];
    int Array1Length = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (Array1Length > MAX_SIZE)
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1;
    }
    FillArrayWithRandomNumbers(Array1, Array1Length);
    int Array2[MAX_SIZE], Array2Length = 0;
    CopyArray(Array1, Array2, Array1Length, Array2Length);
    cout << "\nArray 1 Elements:\n";
    PrintArrayElements(Array1, Array1Length);
    cout << "\n\nArray 2 Elements after copy:\n";
    PrintArrayElements(Array2, Array2Length);
    return 0;
}