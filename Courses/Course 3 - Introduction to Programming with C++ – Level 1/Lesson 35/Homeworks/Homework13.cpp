#include <iostream>
#include <cmath>
using namespace std;
int TotalSeconds(int Days , int Hours , int Minutes , int Seconds)
{
  int TotalSeconds = Seconds + (Minutes*60) + (Hours*3600) + (Days*86400);  
  return TotalSeconds;
}
int main()
{
    int Seconds , Minutes , Hours , Days;
    cout << "Please enter the number of Seconds: " << endl , cin >> Seconds;
    cout << "Please enter the number of Minutes: " << endl , cin >> Minutes;
    cout << "Please enter the number of Hours: " << endl , cin >> Hours;
    cout << "Please enter the number of Days: " << endl , cin >> Days;
    cout << TotalSeconds(Days , Hours , Minutes , Seconds) << " Seconds";
}