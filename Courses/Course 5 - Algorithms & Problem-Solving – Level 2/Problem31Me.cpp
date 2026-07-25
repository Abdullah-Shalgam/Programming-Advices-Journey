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

void FillArrayWithOrderedNumbersFrom1ToN(int Array [100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array [i] = i + 1;
    }
}

void Swap(int& num1, int& num2) 
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void ShuffleArray(int Array [100], int ArrayLength)
{
    for (int i = ArrayLength - 1; i > 0; i--) 
    {
        Swap(Array[i], Array[RandomIntNumber(0, i)]);
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
    int Array[MAX_SIZE];
    int ArrayLength = ReadPositiveNumber("Please enter how many elements you want (Max 100)?: ");
    if (ArrayLength > MAX_SIZE) 
    {
        cout << "Sorry, max allowed elements is " << MAX_SIZE << endl;
        return 1; 
    }
    FillArrayWithOrderedNumbersFrom1ToN(Array, ArrayLength);
    cout << "\nArray elements before shuffle: \n";
    PrintArrayElements(Array, ArrayLength);
    ShuffleArray(Array, ArrayLength);
    cout << "\nArray elements after shuffle: \n";
    PrintArrayElements(Array, ArrayLength);
    return 0;
}