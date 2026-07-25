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

void PrintArrayElements(int Array [100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength;i++)
    {
        cout << Array [i] << " ";
    }
}

int GetSumOfNumbersInArray(int Array [100], int ArrayLength)
{
    int Sum = 0;
    for (int i = 0; i < ArrayLength; i++)
    {
        Sum += Array [i];
    }
    return Sum;
}

float GetAverageOfNumbersInArray(int Array [100], int ArrayLength)
{
    return GetSumOfNumbersInArray(Array, ArrayLength) / (float) ArrayLength;
}

int main()
{
    srand(time(0));
    const int MAX_SIZE = 100;
    int Array[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    FillArrayWithRandomNumbers(Array, ArrayLength);
    cout << "\nArray Elements: ";
    PrintArrayElements(Array, ArrayLength);
    cout << "\nAverage of all numbers is: " << GetAverageOfNumbersInArray(Array, ArrayLength);
    return 0;
}