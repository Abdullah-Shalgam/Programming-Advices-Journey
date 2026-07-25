#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Msg)
{
    float Num;
    cout << Msg;
    cin >> Num;
    return Num;
}

float MySqrt(float Num)
{
    if (Num > 0)
    {
        float Guess = Num / 2;
        float NewGuess = 0;
        float Epsilon = 0.00001;
        do
        {
            NewGuess = (Guess + (Num / Guess)) / 2;
            if (abs(NewGuess - Guess) < Epsilon)
                return NewGuess;
            Guess = NewGuess;
        } while (true);
    }
    else if (Num == 0)
        return 0;
    else
        return NAN;
}

int main()
{
    float Num = ReadNumber("Please Enter a Number: ");
    cout << "\nMy Sqrt Result: " << MySqrt(Num);
    cout << "\nC++ Result: " << sqrt(Num);
    return 0;
}