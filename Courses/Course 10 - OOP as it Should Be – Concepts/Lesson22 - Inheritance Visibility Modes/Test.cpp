#include <iostream>
using namespace std;

//===================== Base =====================

class clsBase
{
public:
    string PublicVar = "Public Member";

protected:
    string ProtectedVar = "Protected Member";

private:
    string PrivateVar = "Private Member";

public:
    void PrintBase()
    {
        cout << "Base Class\n";
        cout << "Public    : " << PublicVar << endl;
        cout << "Protected : " << ProtectedVar << endl;
        cout << "Private   : " << PrivateVar << endl;
    }
};

//===================== PUBLIC =====================

class clsPublicFather : public clsBase
{
public:

    void Test()
    {
        cout << "\n----- Public Father -----\n";

        cout << PublicVar << endl;      // OK
        cout << ProtectedVar << endl;   // OK

        //cout << PrivateVar << endl;   // ERROR
    }
};

class clsPublicSon : public clsPublicFather
{
public:

    void Test()
    {
        cout << "\n----- Public Son -----\n";

        cout << PublicVar << endl;      // OK
        cout << ProtectedVar << endl;   // OK
    }
};

//===================== PROTECTED =====================

class clsProtectedFather : protected clsBase
{
public:

    void Test()
    {
        cout << "\n----- Protected Father -----\n";

        cout << PublicVar << endl;      // OK
        cout << ProtectedVar << endl;   // OK
    }
};

class clsProtectedSon : public clsProtectedFather
{
public:

    void Test()
    {
        cout << "\n----- Protected Son -----\n";

        cout << PublicVar << endl;      // OK
        cout << ProtectedVar << endl;   // OK
    }
};

//===================== PRIVATE =====================

class clsPrivateFather : private clsBase
{
public:

    void Test()
    {
        cout << "\n----- Private Father -----\n";

        cout << PublicVar << endl;      // OK
        cout << ProtectedVar << endl;   // OK
    }
};

class clsPrivateSon : public clsPrivateFather
{
public:

    void Test()
    {
        cout << "\n----- Private Son -----\n";

        //cout << PublicVar << endl;      // ERROR
        //cout << ProtectedVar << endl;   // ERROR

        cout << "Cannot access inherited members.\n";
    }
};

//===================== MAIN =====================

int main()
{
    clsPublicFather PublicFather;
    clsProtectedFather ProtectedFather;
    clsPrivateFather PrivateFather;

    PublicFather.Test();
    ProtectedFather.Test();
    PrivateFather.Test();

    cout << "\n=====================================\n";

    clsPublicSon PublicSon;
    clsProtectedSon ProtectedSon;
    clsPrivateSon PrivateSon;

    PublicSon.Test();
    ProtectedSon.Test();
    PrivateSon.Test();

    cout << "\n=====================================\n";

    cout << "Access from Outside:\n\n";

    clsPublicFather PF;
    cout << PF.PublicVar << endl;          // OK

    clsProtectedFather PrF;
    //cout << PrF.PublicVar << endl;       // ERROR

    clsPrivateFather PvF;
    //cout << PvF.PublicVar << endl;       // ERROR

    return 0;
}