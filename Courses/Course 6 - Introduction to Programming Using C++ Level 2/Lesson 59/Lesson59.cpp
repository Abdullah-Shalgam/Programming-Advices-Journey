#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    time_t t = time(0);
    char * dt = ctime(&t);
    cout << "Local Time:\n\n" << dt;
    tm * pGmtm = gmtime(&t);
    dt = asctime(pGmtm);
    cout << "\n\nUTC Time:\n\n" << dt;
}