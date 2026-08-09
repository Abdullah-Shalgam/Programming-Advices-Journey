#include <iostream>
#include "clsInputValidate.h"

using namespace std;

// 1. اختبار دوال التحقق من التواريخ و الـ Templates
void TestValidationUtilities()
{
    cout << "\n============================================\n";
    cout << "  1. Testing Templates & Date Validation    \n";
    cout << "============================================\n";

    // Testing IsNumberBetween (Template)
    cout << "Is 5 between 1 and 10? " 
         << (clsInputValidate::IsNumberBetween(5, 1, 10) ? "Yes" : "No") << "\n";
    
    cout << "Is 15.5 between 1.0 and 10.0? " 
         << (clsInputValidate::IsNumberBetween(15.5, 1.0, 10.0) ? "Yes" : "No") << "\n\n";

    // Testing IsValideDate
    clsDate ValidDate(15, 8, 2026);
    clsDate InvalidDate(35, 13, 2026);

    cout << "Is (15/8/2026) Valid Date? " 
         << (clsInputValidate::IsValideDate(ValidDate) ? "Yes" : "No") << "\n";
    
    cout << "Is (35/13/2026) Valid Date? " 
         << (clsInputValidate::IsValideDate(InvalidDate) ? "Yes" : "No") << "\n\n";

    // Testing IsDateBetween
    clsDate DateFrom(1, 1, 2026);
    clsDate DateTo(31, 12, 2026);

    cout << "Is (15/8/2026) between (1/1/2026) and (31/12/2026)? " 
         << (clsInputValidate::IsDateBetween(ValidDate, DateFrom, DateTo) ? "Yes" : "No") << "\n";
}

// 2. اختبار دوال قراءة الأرقام الصحيحة (Integers)
void TestIntegerReading()
{
    cout << "\n============================================\n";
    cout << "  2. Testing Integer Reading Functions      \n";
    cout << "============================================\n";

    // ReadIntNumber (Custom Message)
    int Age = clsInputValidate::ReadIntPositiveNumber("Enter your age: ");
    cout << "-> Your Age is: " << Age << "\n\n";

    // ReadIntNumber (Default Message)
    int Number = clsInputValidate::ReadIntNumber();
    cout << "-> Entered Number: " << Number << "\n\n";

    // ReadIntPositiveNumber
    int PositiveNum = clsInputValidate::ReadIntPositiveNumber("Enter a positive integer: ");
    cout << "-> Positive Number: " << PositiveNum << "\n\n";

    // ReadIntNumberInRange
    int Month = clsInputValidate::ReadIntNumberInRange(1, 12, "Enter Month (1 - 12): ");
    cout << "-> Month Entered: " << Month << "\n\n";

    // ReadLongLongPositiveNumber
    long long NationalID = clsInputValidate::ReadLongLongPositiveNumber("Enter National ID (Positive Long Long): ");
    cout << "-> National ID: " << NationalID << "\n";
}

// 3. اختبار دوال قراءة الأرقام العشرية (Doubles)
void TestDoubleReading()
{
    cout << "\n============================================\n";
    cout << "  3. Testing Double Reading Functions       \n";
    cout << "============================================\n";

    // ReadDblNumber
    double Salary = clsInputValidate::ReadDblNumber("Enter Salary: ");
    cout << "-> Salary: " << Salary << "\n\n";

    // ReadDblPositiveNumber
    double Distance = clsInputValidate::ReadDblPositiveNumber("Enter Distance in km: ");
    cout << "-> Distance: " << Distance << "\n\n";

    // ReadDblNumberInRange
    double Rate = clsInputValidate::ReadDblNumberInRange(0.0, 5.0, "Enter Rating (0.0 to 5.0): ");
    cout << "-> Rate: " << Rate << "\n";
}

// 4. اختبار دوال قراءة النصوص والحروف
void TestTextAndCharReading()
{
    cout << "\n============================================\n";
    cout << "  4. Testing Text & Character Functions     \n";
    cout << "============================================\n";

    // ReadText
    string FullName = clsInputValidate::ReadText("Enter your Full Name: ");
    cout << "-> Full Name: " << FullName << "\n\n";

    // ReadCharacter
    char Code = clsInputValidate::ReadCharacter("Enter Security Character: ");
    cout << "-> Character: " << Code << "\n\n";

    // getYesNoAnswer
    char Answer = clsInputValidate::getYesNoAnswer("Do you agree to terms? (Y/N): ");
    cout << "-> Answer: " << Answer << "\n";
}

int main()
{
    cout << "============================================\n";
    cout << "     clsInputValidate Library Test Suite    \n";
    cout << "============================================\n";

    TestValidationUtilities();
    TestIntegerReading();
    TestDoubleReading();
    TestTextAndCharReading();

    cout << "\n============================================\n";
    cout << "      All Tests Executed Successfully!      \n";
    cout << "============================================\n";

    return 0;
}