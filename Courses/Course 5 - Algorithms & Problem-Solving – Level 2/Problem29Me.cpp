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

bool isPrime(int i)
{
    if (i <= 1)
        return false;
    for (int j = 2; j * j <= i; j++)
    {
        if (i % j == 0)
            return false;
    }
    return true;
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

void CopyOnlyPrimeNumbersFromArray (int ArraySource[100], int ArrayDestination[100], int ArrayLength, int &Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (isPrime(ArraySource[i]))
        {
            ArrayDestination [Array2Length] = ArraySource [i];
            Array2Length++;
        }
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
    int Array2[MAX_SIZE] , Array2Length = 0;
    CopyOnlyPrimeNumbersFromArray (Array1, Array2, ArrayLength, Array2Length);
    cout << "\nArray 1 Elements: \n";
    PrintArrayElements(Array1, ArrayLength);
    cout << "\n\nPrime Numebrs in Array 2: \n";
    if (Array2Length == 0)
        cout << "There is no prime numbers in this array.";
    else
        PrintArrayElements(Array2, Array2Length);
    return 0;
}