#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector <int> vNums;
    vNums.push_back(10);
    vNums.push_back(20);
    vNums.push_back(30);
    vNums.push_back(40);
    vNums.push_back(50);
    cout << "First Element: " << vNums.front() << endl;
    cout << "Last Element: " << vNums.back() << endl;
    //returns the number of elements present in the vector
    cout << "Size: " << vNums.size() << endl;
    //check the overall size of a vector
    cout << "Capacity : " << vNums.capacity() << endl;
    //returns 1 (true) if the vector is empty
    cout << "Empty : " << vNums.empty() << endl;
    return 0;
}