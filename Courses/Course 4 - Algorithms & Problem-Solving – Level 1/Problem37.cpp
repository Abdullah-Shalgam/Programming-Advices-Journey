#include <iostream>
using namespace std;

float ReadNumber(int i)
{
    float N;
    cout << "Please Enter the number " << i << " : ";
    cin >> N;
    return N;
}

int SumUntil(int Until)
{
    int Sum = 0;
    int Num;
    int i = 1;
    do
    {
        Num = ReadNumber(i);
        if (Num == Until)
            return Sum;
        Sum += Num;
        i++;
    } while (true);
}

void PrintSum(int Sum)
{
    cout << "\nSum of Numbers = " << Sum;
}

int main()
{
    PrintSum(SumUntil(-99));
    return 0;
}