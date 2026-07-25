#include <iostream>
#include <cmath>
using namespace std;
void Seconds_TO_DaysHoursMinutesSeconds()
{
    int TotalSeconds;
    cout << "Please enter the Total Seconds: " << endl , cin >> TotalSeconds;
    int D = TotalSeconds/86400;
    int H = (TotalSeconds%86400)/3600;
    int M = ((TotalSeconds%86400)%3600)/60;
    int S = ((TotalSeconds%86400)%3600)%60;
    cout << endl << endl << D << ":" << H << ":" << M << ":" << S;
}
int main()
{
    Seconds_TO_DaysHoursMinutesSeconds();
}