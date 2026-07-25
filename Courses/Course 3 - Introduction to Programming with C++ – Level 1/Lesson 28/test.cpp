#include <iostream>
using namespace std;
enum Color {Red, Blue, Green, Yellow};
enum Country {Libya, Eygpt, UAE, Moroco, USA , UK};
int main()
{
Color CarColor;
Country Carmade;
CarColor = Color::Green;
Carmade = Country::Eygpt;
cout << CarColor << endl << Carmade;
return 0;
}