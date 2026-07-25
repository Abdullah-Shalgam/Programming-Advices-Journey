#include <iostream>
using namespace std;

struct stInfo
{
    short Age;
    bool HasDrivingLicense;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please Enter Your Age : ";
    cin >> Info.Age;
    
    cout << "Do you have a driving licensce : ";
    cin >> Info.HasDrivingLicense;
    
    return Info;
}

bool isAccepted(stInfo Info)
{
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