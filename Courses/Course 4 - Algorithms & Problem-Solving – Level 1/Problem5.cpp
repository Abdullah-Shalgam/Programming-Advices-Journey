#include <iostream>
#include <cstdlib>
using namespace std;

struct stInfo
{
    short Age;
    bool HasDrivingLicense;
    bool HasWasta;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Do you have a wasta : ";
    cin >> Info.HasWasta;

    cout << "Please Enter Your Age : ";
    cin >> Info.Age;

    cout << "Do you have a driving licensce : ";
    cin >> Info.HasDrivingLicense;

    return Info;
}

bool isAccepted(stInfo Info)
{
    if (Info.HasWasta)
        return true;
    else
        return (Info.Age >= 21 && Info.HasDrivingLicense);
}

void PrintResult(stInfo Info)
{
    if (isAccepted(Info))
        cout << "\nHired";
    else
        cout << "\nRejected";
}

int main()
{
    PrintResult(ReadInfo());
    return 0;
}