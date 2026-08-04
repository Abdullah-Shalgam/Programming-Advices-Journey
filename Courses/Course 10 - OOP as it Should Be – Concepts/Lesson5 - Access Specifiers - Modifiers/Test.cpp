#include <iostream>

using namespace std;

class clsPerson
{

private:
    short x = 10;
    string S1 = "Hello";

protected:
    short y = 30;
    string S2 = "Welcome";

    string GetNumberOfstring(short Times, string str)
    {
        string String = "";

        for (short i = 1; i <= Times; i++)
        {
            String += str + " - ";
        }

        return String;
    }

public:
    string FirstName = "";
    string LastName = "";

    string GetFullName()
    {
        return FirstName + " " + LastName;
    }

    string GetFullNameXTimes(short Times)
    {
        return GetNumberOfstring(Times, GetFullName());
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Ali";
    Person1.LastName = "Al-Ganodi";

    cout << Person1.GetFullNameXTimes(50);

    return 0;
}