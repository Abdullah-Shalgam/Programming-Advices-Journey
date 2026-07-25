#include <iostream>
#include <ctime>
using namespace std;

int ReadNumber(string Msg)
{
    int Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

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

int FindNumberPositionInArray (int Array [100], int ArrayLength, int NumberToCheck)
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
    int Array[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    FillArrayWithRandomNumbers(Array, ArrayLength);
    cout << "\nArray 1 Elements: \n";
    PrintArrayElements(Array, ArrayLength);
    cout << "\n\n\n";
    int NumberToCheck = ReadNumber("Please enter a number to search for?: ");
    int NumPosition = FindNumberPositionInArray(Array, ArrayLength, NumberToCheck);
    cout << "\nNumber you are looking for is: " << NumberToCheck;
    if (NumPosition != -1)
    {
        cout << "\nThe number found at position: " << NumPosition;
        cout << "\nThe number found it's order: " << NumPosition + 1;
    }
    else
        cout << "\nThe number is not found :-(";
    return 0;
}