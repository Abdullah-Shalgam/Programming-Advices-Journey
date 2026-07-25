#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNums = {1, 2, 3, 4, 5};
    try
    {
        cout << vNums.at(8) << endl;
    }
    catch(const std::exception& e)
    {
        cout << "Bro What The Hell Are You DOING!!!";
    }
}