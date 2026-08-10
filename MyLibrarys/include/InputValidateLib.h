#pragma once
#include <string>
#include "DateLib.h"

class InputValidateLib 
{
private:
    static string _ReadPinMasked(string Msg = "Enter PIN Code: ");

public:
    // Basic Input Validations with Default Messages & Error Messages
    static int ReadIntNumber(std::string Msg = "Please enter a number: ", std::string ErrMsg = "Invalid Number, Enter again: ");
    static int ReadIntPositiveNumber(std::string Msg = "Please enter a positive number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    static int ReadIntNumberInRange(int From, int To, std::string Msg = "Please enter a number in range: ", std::string ErrMsg = "Number is not within range, Enter again: ");
    
    static long long ReadLongLongPositiveNumber(std::string Msg = "Please enter a positive number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    
    static double ReadDblNumber(std::string Msg = "Please enter a double number: ", std::string ErrMsg = "Invalid Number, Enter again: ");
    static double ReadDblPositiveNumber(std::string Msg = "Please enter a positive double number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    static double ReadDblNumberInRange(double From, double To, std::string Msg = "Please enter a double number in range: ", std::string ErrMsg = "Number is not within range, Enter again: ");
    
    static std::string ReadText(std::string Msg = "Please enter text: ", std::string ErrMsg = "Invalid Input, Enter again: ");
    static char ReadCharacter(std::string Msg = "Please enter a character: ", std::string ErrMsg = "Invalid Character, Enter again: ");
    static char getYesNoAnswer(std::string Msg = "Please enter (Y/N): ", std::string ErrMsg = "Invalid Answer! Please enter (Y/N): ");
    
    // Date Utilities
    static bool IsDateBetween(DateLib Date, DateLib Date1, DateLib Date2);
    static bool IsValideDate(DateLib Date);

    // PinCode Valedation
    static string GetValidPIN(std::string Msg = "Enter PinCode (4 digits): ", std::string ErrMsg = "\nError: PIN must be exactly 4 digits.\n\n");

    // Template Function
    template <typename T>
    static bool IsNumberBetween(T Num, T From, T To)
    {
        return (Num >= From && Num <= To);
    }
};