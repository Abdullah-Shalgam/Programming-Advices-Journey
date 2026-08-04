#include <iostream>

using namespace std;

class clsPerson
{

private:
    int x = 0;
    string S1 = "";
public:
    string FirstName = "";
    string LastName = "";

    string GetFullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "KoKo";
    Person1.LastName = "MoMo";

    cout << Person1.GetFullName() << endl;

    return 0;
}