#include <iostream>
using namespace std;

int ReadPositiveNumber(string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
}

int ReversedNumber(int Num)
{
    int Remainder = 0 , Reversed = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num /= 10;
        Reversed = Reversed * 10 + Remainder;
    }
    return Reversed;
}

bool IsPalindrome(int Num)
{
    return (Num == ReversedNumber(Num));
}

void PrintIsPalindrome(bool IsPalindrome)
{
    cout << endl;
    if (IsPalindrome)
        cout << "Yes, it is a palindrome number.";
    else
        cout << "No, it is NOT a palindrome number.";
}

int main()
{
    PrintIsPalindrome(IsPalindrome(ReadPositiveNumber("Please enter a number : ")));
    return 0;
}