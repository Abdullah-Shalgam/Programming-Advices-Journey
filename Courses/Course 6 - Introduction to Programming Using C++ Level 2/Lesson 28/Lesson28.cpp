#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNumbers = {10, 20, 30, 40, 50, 60, 70, 80};
    cout << "Vector Elements = ";
    for (int &N : vNumbers)
    {
        cout << N << " ";
    }
}
