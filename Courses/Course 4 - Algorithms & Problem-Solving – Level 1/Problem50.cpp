#include <iostream>
using namespace std;

int ReadPinCode()
{
    int Num;
    cout << "Please enter the ATM PIN code: ";
    cin >> Num;
    return Num;
}

bool CheckPinCode()
{
    int PinCode;
    int Counter = 3;
    do
    {
        PinCode = ReadPinCode();
        if (PinCode == 1234)
            return true;
        else
        {
            Counter--;
            system("color 4F"); //Turn Screen Red
            cout << "\nWrong PIN, You have " << Counter << " more tries\n\n";
        }
        if (Counter == 0)
            return false;
    } while (true);
}

void PrintBalance()
{
    if (CheckPinCode())
    {
        system("color 2F"); //Turn Screen Green
        cout << "\nYour account Balance is: 7500";
    }
    else
        cout << "Your card blocked call the bank for help.";
}
int main()
{
    PrintBalance();
    return 0;
}