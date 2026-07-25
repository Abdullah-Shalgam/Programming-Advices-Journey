#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char x , w;
    x = toupper('y');
    w = tolower('Y');
    cout << x << endl;
    cout << w << endl;
    cout << isupper(x) << endl;
    cout << islower(w) << endl;
    cout << isdigit('8') << endl;
    cout << ispunct('*') << endl;
}