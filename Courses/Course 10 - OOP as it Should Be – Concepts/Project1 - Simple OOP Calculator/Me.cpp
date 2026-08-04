#include <iostream>
#include <string>

using namespace std;

class clsCalculator
{
private:
    float _Result = 0;
    float _LastNumber = 0;
    float _PreviousResult = 0;
    string _LastOperation = "Clear";

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public:

    void Add(float Number)
    {
        _LastOperation = "Adding";
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result += Number;
    }

    void Subtract(float Number)
    {
        _LastOperation = "Subtracting";
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result -= Number;
    }

    void Multiply(float Number)
    {
        _LastOperation = "Multiplying";
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result *= Number;
    }

    void Divide(float Number)
    {
        _LastNumber = Number;

        if (_IsZero(Number)) 
        {
            Number = 1;
        }

        _LastOperation = "Dividing";
        _PreviousResult = _Result;
        _Result /= Number;
    }

    float GetFinalResult()
    {
        return _Result;
    }

    void Clear()
    {
        _LastOperation = "Clear";
        _LastNumber = 0;
        _PreviousResult = 0;
        _Result = 0;
    }

    void CancelLastOperation()
    {
        _LastOperation = "Cancelling Last Operation";
        _LastNumber = 0;
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
    }
};

int main()
{
    clsCalculator Calc1;

    Calc1.Clear();

    Calc1.Add(10);
    Calc1.PrintResult();

    Calc1.Add(100);
    Calc1.PrintResult();

    Calc1.Subtract(20);
    Calc1.PrintResult();

    Calc1.Divide(0);
    Calc1.PrintResult();

    Calc1.Divide(2);
    Calc1.PrintResult();

    Calc1.Multiply(3);
    Calc1.PrintResult();

    Calc1.CancelLastOperation();
    Calc1.PrintResult();

    Calc1.Clear();
    Calc1.PrintResult();

    return 0;
}