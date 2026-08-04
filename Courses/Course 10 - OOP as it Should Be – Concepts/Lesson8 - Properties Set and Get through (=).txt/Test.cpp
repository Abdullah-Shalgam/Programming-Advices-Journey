#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _FirstName = "";

public:
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }

    __declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Khalid";
    
    cout << "FirstName: " << Person1.FirstName;

    return 0;
}