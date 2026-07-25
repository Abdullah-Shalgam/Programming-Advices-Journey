#include <iostream>
using namespace std;
int main()
{
    int N1 , N2;
    string OprationType;
    cout << "Enter Numbre 1 : \n";
    cin >> N1;
    cout << "Enter Number 2 : \n";
    cin >> N2;
    cout << "Enter The Opration Type : \n";
    cin >> OprationType;
    if (OprationType == "+")
    {
        cout << N1 + N2;
    }
    else if (OprationType == "-")
    {
        cout << N1 - N2;
    }
    else if (OprationType == "*")
    {
        cout << N1 * N2;
    }
    else if (OprationType == "/")
    {
        cout << N1 / N2;
    }
    else
    {
        cout << "Invalid Value";
    }
    return 0;
}