#include <iostream>
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

void ReadArrayElements(int Array [], int ArrayLength)
{
    cout << "\nEnter array elements: \n";
    for (int i = 0; i <= ArrayLength - 1; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> Array [i];
    }
}

int TimesRepeated(int Array [], int ArrayLength, int CheckNumber)
{
    int Repetition = 0;
    for (int i = 0; i <= ArrayLength - 1; i++)
    {
        if (Array [i] == CheckNumber) Repetition++;
    }
    return Repetition;
}

void PrintArrayElements(int Array [], int ArrayLength)
{
    for (int i = 0; i <= ArrayLength - 1;i++)
    {
        cout << Array [i] << " ";
    }
}

void PrintResult(int Array [], int ArrayLength, int CheckNumber)
{
    cout << "\nOriginal array: ";
    PrintArrayElements(Array, ArrayLength);
    cout << endl << "Number "<< CheckNumber << " is repeated "
    << TimesRepeated(Array, ArrayLength, CheckNumber) << " time(s).";
}

int main()
{
    const int MAX_SIZE = 100;
    int Array[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    ReadArrayElements(Array, ArrayLength);
    int CheckNumber = ReadNumber("\nEnter the number you want to check: ");
    PrintResult(Array, ArrayLength, CheckNumber);
    return 0;
}