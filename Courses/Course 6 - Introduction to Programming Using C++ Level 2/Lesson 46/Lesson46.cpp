#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNums = {1, 2, 3, 4, 7, 4};
    cout << "Print Vector elements using .at method: \n\n";
    for (short i = 0; i < 6; i++)
    {
        cout << vNums.at(i) << endl;
    }
    cout << "\nPrint Vector elements using []: \n\n";
    for (short i = 0; i < 6; i++)
    {
        cout << vNums[i] << endl;
    }
    cout << endl;
    return 0;
}