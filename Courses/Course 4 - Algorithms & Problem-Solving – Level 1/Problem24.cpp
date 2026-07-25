#include <iostream>
using namespace std;

short ReadAge()
{
    short Age;
    cout << "Please enter your age: ";
    cin >> Age;
    return Age;
}

bool ValidateNumberInRange(short Age , short From, short To)
{
    return (Age >= From && Age <= To);
}

void PrintResult(int Age)
{
    if (ValidateNumberInRange(Age, 18, 45))
        cout << "\n" << Age << " is a valid age.";
    else
        cout << "\n" << Age << " is an invalid age.";
}

int main()
{
    PrintResult(ReadAge());
    return 0;
}