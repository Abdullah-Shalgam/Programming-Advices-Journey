#include <iostream>
#include <string>
#include "clsDeveloper.h"

using namespace std;

int main()
{
    clsDeveloper Developer1(10, "Ali", "Al-Ganodi", "Ali@gmail.com", "0912345678", 
                           "Software Engineer", 5000, "IT", "C++");

    Developer1.Print();

    Developer1.SendEmail("Task Update", "The project code is clean and refactored.");
    Developer1.SendSMS("Hello World!");

    return 0;
}