#include <iostream>
using namespace std;

void ReadAge(short &Age)
{
    cout << "Please enter age between 18 and 45: ";
    cin >> Age;
}

bool ValidateNumberInRange(short Age , short From, short To)
{
    return (Age >= From && Age <= To);
}

short ReadUntilAgeBetween(short From, short To)
{
    short Age;
    do
    {
        ReadAge(Age);
    }
    while (!ValidateNumberInRange(Age, 18, 45));
    return Age;
}

void PrintResult(short Age)
{
    cout << "\nAge = " << Age;
}
int main()
{
    PrintResult(ReadUntilAgeBetween(18, 40));
    return 0;
}