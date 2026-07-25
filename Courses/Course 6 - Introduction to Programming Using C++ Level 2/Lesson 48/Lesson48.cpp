#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNums = {1, 2, 3, 4, 5, 6};
    vector <int>::iterator iteratorNum;
    for (iteratorNum = vNums.begin(); iteratorNum != vNums.end(); iteratorNum++)
    {
        cout << *iteratorNum << endl;
    }
}