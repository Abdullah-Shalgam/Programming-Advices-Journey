#include <iostream>
using namespace std;

string ReadPassword()
{
    string Password;
    cout << "Please enter the password (3 Capital Letters): ";
    cin >> Password;
    return Password;
}

bool CheckPassWord(string Password)
{
    string Word = "";
    int Counter = 1;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int f = 65; f <= 90; f++)
            {
                Word += char(i);
                Word += char(j);
                Word += char(f);
                cout << "Trial [" << Counter << "] : " << Word << endl;
                if (Password == Word)
                {
                    cout << "\n\nPassword is " << Word << "\nFound after " << Counter << " Trial(s).";
                    return true;
                }
                Word = "";
                Counter++;
            }
        }
    }
    cout << "Sory we couldn't find the password";
    return false;
}

int main()
{
    CheckPassWord(ReadPassword());
    return 0;
}