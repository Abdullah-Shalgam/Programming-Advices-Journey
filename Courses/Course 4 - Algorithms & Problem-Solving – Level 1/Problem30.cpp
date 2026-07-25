#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    do
    {
        int Num;
        cout << Message;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Number, Try again\n";
    } while (true);
    
}

int CalculateFactorial(int Num)
{
    int Sum = 1;
    for (int i = Num; i >= 1; i--)
    {
        Sum *= i;
    }
    return Sum;
}

void PrintResult(int Num, int Factorial)
{
    cout << "The Factorial of " << Num << " = " << Factorial;
}
int main()
{
    int Num = ReadPositiveNumber("Please Enter a positive number: ");
    int Factorial = CalculateFactorial(Num);
    PrintResult(Num, Factorial);
    return 0;
}