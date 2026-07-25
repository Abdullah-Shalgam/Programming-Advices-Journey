#include <iostream>
#include <cstdlib> // لدالة rand و srand
#include <ctime>   // لدالة time

void fillArrayNumber(int arr[])
{
    const int SIZE = 10000;
    arr[SIZE];
    // ضبط "البذرة" بناءً على وقت الجهاز الحالي لضمان أرقام مختلفة كل مرة
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand(); // توليد رقم عشوائي
    }
}

int main()
{
    int ArrayofNumbers[10000];
    fillArrayNumber(ArrayofNumbers);
    for (int i = 1; i < 10000; i++)
    {
        std::cout << "Number " << i+1 << " Value is: " << ArrayofNumbers[i] << std::endl;
    }
}