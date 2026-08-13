#pragma once
#include <string>
#include "DateLib.h"

class InputValidateLib
{
private:
    static std::string _ReadPinMasked(std::string Msg = "Enter PIN Code: ");

public:
    // ─── Int Validations ───
    static int ReadIntNumber(std::string Msg = "Please enter a number: ", std::string ErrMsg = "Invalid Number, Enter again: ");
    static int ReadIntPositiveNumber(std::string Msg = "Please enter a positive number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    static int ReadIntNumberInRange(int From, int To, std::string Msg = "Please enter a number in range: ", std::string ErrMsg = "Number is not within range, Enter again: ");

    // ─── Short Validations ───
    static short ReadShortNumber(std::string Msg = "Please enter a short number: ", std::string ErrMsg = "Invalid Number, Enter again: ");
    static short ReadShortPositiveNumber(std::string Msg = "Please enter a positive short number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    static short ReadShortNumberInRange(short From, short To, std::string Msg = "Please enter a short number in range: ", std::string ErrMsg = "Number is not within range, Enter again: ");

    // ─── Long Long Validations ───
    static long long ReadLongLongPositiveNumber(std::string Msg = "Please enter a positive number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");

    // ─── Double Validations ───
    static double ReadDblNumber(std::string Msg = "Please enter a double number: ", std::string ErrMsg = "Invalid Number, Enter again: ");
    static double ReadDblPositiveNumber(std::string Msg = "Please enter a positive double number: ", std::string ErrMsg = "Invalid Positive Number, Enter again: ");
    static double ReadDblNumberInRange(double From, double To, std::string Msg = "Please enter a double number in range: ", std::string ErrMsg = "Number is not within range, Enter again: ");

    // ─── Text & Character Validations ───
    static std::string ReadText(std::string Msg = "Please enter text: ", std::string ErrMsg = "Invalid Input, Enter again: ");
    static char ReadCharacter(std::string Msg = "Please enter a character: ", std::string ErrMsg = "Invalid Character, Enter again: ");
    static char getYesNoAnswer(std::string Msg = "Please enter (Y/N): ", std::string ErrMsg = "Invalid Answer! Please enter (Y/N): ");

    // ─── Date Utilities ───
    static bool IsDateBetween(DateLib Date, DateLib Date1, DateLib Date2);
    static bool IsValideDate(DateLib Date);

    // ─── Password / Masked Text Utilities ───
    static std::string ReadPassword(std::string Msg = "Enter Password: ", short MinLength = 4, std::string ErrMsg = "\nError: Invalid Password!\n\n");
    static std::string GetValidPIN(std::string Msg = "Enter PinCode (4 digits): ", std::string ErrMsg = "\nError: PIN must be exactly 4 digits.\n\n");

    // ─── Template Functions ───
    template <typename T>
    static bool IsNumberBetween(T Num, T From, T To)
    {
        return (Num >= From && Num <= To);
    }
};