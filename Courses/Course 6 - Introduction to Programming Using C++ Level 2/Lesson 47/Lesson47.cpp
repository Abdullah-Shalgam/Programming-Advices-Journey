#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNumbers = {1, 2, 3, 4, 5, 6};
    cout << "Original Vector: ";
    for (const int & i : vNumbers)
    {
        cout << i << " ";
    }
    cout << "\nUpdate Vector 1: ";
    for (int & i : vNumbers)
    {
        i = 20;
        cout << i << " ";
    }
    cout << "\nUpdate Vector 2: ";
    vNumbers[0] = 10;
    vNumbers[1] = 20;
    vNumbers.at(2) = 30;
    vNumbers.at(3) = 40;
    for (const int & Num : vNumbers)
    {
        cout << Num << " ";
    }
}