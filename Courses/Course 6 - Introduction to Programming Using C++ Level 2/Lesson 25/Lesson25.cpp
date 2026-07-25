#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char Name[] = "Mohammed Abu-Hadhoud";
    char SchoolName[] = "Programming Advices";
    char RandomName[] = "Abd-Alqasim Alfrjani";
    // print string and String
    printf("Dear %.3s, How are you?\n\n", Name);
    printf("Welcome to %s School!\n\n", SchoolName);
    printf("Hello %s, Do you need anything?\n", RandomName);
    char c = 'S';
    char koko = 'g';
    printf("Setting the width of c :%*c \n", 1, c);
    printf("Setting the width of c :%*c \n", 2, c);
    printf("Setting the width of c :%*c \n", 3, c);
    printf("Setting the width of c :%*c \n", 4, c);
    printf("Setting the width of c :%*c \n", 5, c);
    printf("Haha (   g%*c   )", 3, koko);
    return 0;
}