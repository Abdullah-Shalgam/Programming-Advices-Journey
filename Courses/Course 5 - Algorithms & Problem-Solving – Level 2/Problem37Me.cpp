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

void AddArrayElement(int Number, int Array [100], int &ArrayLength)
{
    Array[ArrayLength] = Number;
    ArrayLength++;
}

void InputUserNumbersInArray(int Array [100], int &ArrayLength)
{
    int Num = 0;
    bool Choice = true;
    do
    {
        Num = ReadNumber("Please enter a number?: ");
        AddArrayElement(Num, Array, ArrayLength);
        if (ArrayLength > 99)
        {
            cout << "Sorry, you have reached the maximum addition limit.";
            break;
        }
        cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes?: ";
        cin >> Choice;
        cout << "\n\n";
    } while (Choice);
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
    InputUserNumbersInArray(Array, ArrayLength);
    cout << "Array Length = " << ArrayLength;
    cout << "\nArray elements: ";
    PrintArrayElements(Array, ArrayLength);
    return 0;
}