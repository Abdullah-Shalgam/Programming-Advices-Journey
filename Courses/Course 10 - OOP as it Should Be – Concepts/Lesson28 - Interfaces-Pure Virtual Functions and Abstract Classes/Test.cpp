#include <iostream>

using namespace std;

//Abstract Class / Interface / Contract.
class clsMobile
{
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber,string Text) = 0;
    virtual void TakePicture() = 0;
public:
    void Test(string Test)
    {
        cout << Test;
    }

    virtual ~clsMobile() {}
};

class clsiPhone : public clsMobile
{
//This class signed a contract with clsMobile abstract class
//therefore it should implement everything in the abstract class.
public:
    void Dial(string PhoneNumber) override
    {
    }
    void SendSMS(string PhoneNumber, string Text) override
    {
    }
    void TakePicture() override
    {
    }
    void MyOwnMethod()
    {
    }

    virtual ~clsiPhone() override {}
};

class clsSamsungNote10 : public clsMobile
{
//This class signed a contract with clsMobile abstract class
//therefore it should implement everything in the abstract class
public:
    void Dial(string PhoneNumber) override
    {
    }
    void SendSMS(string PhoneNumber, string Text) override
    {
    }
    void TakePicture() override
    {
    }

    virtual ~clsSamsungNote10() override {}
};

int main()
{
    clsiPhone iPhone1;

    iPhone1.Test("Hello");

    clsSamsungNote10 Note10;

    return 0;
}