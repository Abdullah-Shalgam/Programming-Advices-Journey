#include <iostream>
#include <cmath>
using namespace std;
int main()
{
const float Pi = 3.14;
float D;
cout << "Please enter the Diameter: " << endl , cin >> D;
float Area = (Pi*pow(D , 2))/4;
cout << endl << Area << endl << ceil(Area);
return 0;
}