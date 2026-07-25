#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomIntNumber (int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Print3RandomNumbres()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << RandomIntNumber(1, 10) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Print3RandomNumbres();
    return 0;
}