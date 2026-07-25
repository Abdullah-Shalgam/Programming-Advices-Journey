#include <iostream>
using namespace std;

int ReadPinCode()
{
    int Num;
    do
    {
        cout << "Please enter the ATM PIN code: ";
        cin >> Num;
        if (Num >= 0)
            return Num;
        cout << "\nInvalid Input!\n";
    } while (true);
}

bool CheckPinCode()
{
    int PinCode;
    do
    {
        PinCode = ReadPinCode();
        if (PinCode == 1234)
            return true;
        system("color 4F");
        cout << "\nWrong PIN\n";
    } while (true);
}

void PrintBalance()
{
    if (CheckPinCode())
    {
        system("color 2F");
        cout << "\nYour Balance is: 7500";
    }
}

int main()
{
    PrintBalance();
    return 0;
}