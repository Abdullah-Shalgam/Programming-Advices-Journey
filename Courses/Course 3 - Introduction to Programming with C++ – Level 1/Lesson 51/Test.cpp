#include <iostream>
using namespace std;

int ReadIntNumberInRange(int From, int To) {
    int Number;
    do
    {
        cout << "Please enter a number between " << From << " and " << To << ": " << endl;
        cin >> Number;
    } 
    while (Number < From || Number > To);
    return Number;
}

int main() 
{
    int Number = ReadIntNumberInRange(1,10);
    cout << "The number you entered is: " << Number;
    return 0;
}