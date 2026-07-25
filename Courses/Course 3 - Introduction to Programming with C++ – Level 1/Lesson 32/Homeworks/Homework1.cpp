#include <iostream>
using namespace std;
void DisplayMyCardInfo()
{
string Name , City , Country;
unsigned short int Age;
cout << "Please enter your Name: " , getline(cin, Name);
cout << "Please enter your Age: " , cin >> Age;
cout << "Please enter your City: " , cin >> City;
cout << "Please enter your Country:" , cin >> Country;
}
void SquareStars()
{
cout << "**********" << endl;
cout << "**********" << endl;
cout << "**********" << endl;
cout << "**********" << endl;
cout << "**********";
}
void IloveProgramming()
{
cout << "I love Programming!" << "\n\n";
cout << "I Want to be the best developer ever!" << "\n\n";
cout << "I know it will take some time to practice, but i will achieve my gool." << "\n\n";
cout << "Best regards:" << endl << "Mohammed Abu-Hadhoud";
}
void H_ShapedStars()
{
cout << "*       *" << endl;
cout << "*       *" << endl;
cout << "*       *" << endl;
cout << "*********" << endl;
cout << "*       *" << endl;
cout << "*       *" << endl;
cout << "*       *" << endl;
}
int main()
{
    DisplayMyCardInfo();
    cout << "\n\n";
    SquareStars();
    cout << "\n\n";
    IloveProgramming();
    cout << "\n\n";
    H_ShapedStars();
return 0;
}