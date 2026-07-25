#include <iostream>
using namespace std;
struct BmwCar
{
int Year;
string Model;
string Coler;
};
int main()
{
BmwCar Car1;
Car1.Model = "M8";
Car1.Coler = "Blue";
cout << Car1.Coler; 
return 0;
}