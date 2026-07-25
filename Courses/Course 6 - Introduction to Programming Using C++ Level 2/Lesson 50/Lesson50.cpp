#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Str = "Hello My Name is";
    cout << Str.length() << endl;
    cout << Str.append(" Abdullah") << endl;
    cout << Str.insert(0, "Welcome And ") << endl;
    cout << Str.substr(21, 4) << endl;
    Str.push_back('y');
    cout << Str << endl;
    Str.pop_back();
    cout << Str << endl;
    if (Str.find("name") == Str.npos)
        cout << "We could't find the Text." << endl;
    else
        cout << Str.find("Name") << endl;
    Str.clear();
    cout << Str << endl;
}