#include <iostream>
using namespace std;
int main()
{
    int N1 , N2;
    char OprationType;
    cout << "Enter Numbre 1 : \n";
    cin >> N1;
    cout << "Enter Number 2 : \n";
    cin >> N2;
    cout << "Enter The Opration Type (+, -, /, *) : \n";
    cin >> OprationType;
    switch (OprationType)
    {
        case '+':
        cout << N1 + N2;
        break;
        case '-':
        cout << N1 - N2;
        break;
        case '/':
        cout << N1 / N2;
        break;
        case '*':
        cout << N1 * N2;
        break;
        default:
        cout << "Invalid Value";
        break;
    }
    return 0;
}