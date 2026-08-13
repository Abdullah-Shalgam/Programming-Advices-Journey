#include <iostream>
#include "clsUtil.h"

using namespace std;

int main()
{
    // 0. تهيئة بذور توليد الأرقام العشوائية
    clsUtil::Srand();

    cout << "====================================================\n";
    cout << clsUtil::Tabs(2) << "Testing clsUtil Library Features\n";
    cout << "====================================================\n\n";

    // 1. تجربة الأرقام والحروف العشوائية
    cout << "--- 1. Random Number & Character Generation ---\n";
    cout << "Random Number (1 to 100): " << clsUtil::RandomNumber(1, 100) << "\n";
    cout << "Random Small Character  : " << clsUtil::GetRandomCharacter(clsUtil::enCharType::SmallCharacter) << "\n";
    cout << "Random Capital Character: " << clsUtil::GetRandomCharacter(clsUtil::enCharType::CapitalCharacter) << "\n";
    cout << "Random Digit            : " << clsUtil::GetRandomCharacter(clsUtil::enCharType::Digit) << "\n";
    cout << "Random Special Character: " << clsUtil::GetRandomCharacter(clsUtil::enCharType::SpecialCharacter) << "\n";
    cout << "Random Mix Character    : " << clsUtil::GetRandomCharacter(clsUtil::enCharType::MixChars) << "\n\n";

    // 2. تجربة توليد الكلمات المفتاحية والسيريال (Keys)
    cout << "--- 2. Word & Key Generation ---\n";
    cout << "Generated Word (Length 8)  : " << clsUtil::GenerateWord(clsUtil::enCharType::CapitalCharacter, 8) << "\n";
    cout << "Generated Single Key       : " << clsUtil::GenerateKey(clsUtil::enCharType::CapitalCharacter) << "\n\n";
    cout << "Generating 3 Keys:\n";
    clsUtil::GenerateKeys(3, clsUtil::enCharType::CapitalCharacter);
    cout << "\n";

    // 3. تجربة التشفير وفك التشفير
    cout << "--- 3. Encryption & Decryption ---\n";
    string OriginalText = "Hello C++ Developer!";
    short Key = 5;
    string EncryptedText = clsUtil::EncryptText(OriginalText, Key);
    string DecryptedText = clsUtil::DecryptText(EncryptedText, Key);

    cout << "Original Text  : " << OriginalText << "\n";
    cout << "Encrypted Text : " << EncryptedText << "\n";
    cout << "Decrypted Text : " << DecryptedText << "\n\n";

    // 4. تجربة دالة الـ Swap مع الأرقام ومع كائن clsDate
    cout << "--- 4. Template Swap Function ---\n";
    int Num1 = 10, Num2 = 20;
    cout << "Before Swap (Ints)   : Num1 = " << Num1 << ", Num2 = " << Num2 << "\n";
    clsUtil::Swap(Num1, Num2);
    cout << "After Swap (Ints)    : Num1 = " << Num1 << ", Num2 = " << Num2 << "\n\n";

    clsDate Date1(1, 1, 2026), Date2(31, 12, 2026);
    cout << "Before Swap (clsDate): Date1 = " << Date1.DateToString() << ", Date2 = " << Date2.DateToString() << "\n";
    clsUtil::Swap(Date1, Date2);
    cout << "After Swap (clsDate) : Date1 = " << Date1.DateToString() << ", Date2 = " << Date2.DateToString() << "\n\n";

    // 5. تجربة مصفوفات البيانات وإعادة الترتيب العشوائي (Shuffle)
    cout << "--- 5. Array Operations ---\n";
    const int ArrLength = 5;

    // مصفوفة أرقام
    int NumbersArr[ArrLength];
    clsUtil::FillArrayWithRandomNumbers(NumbersArr, ArrLength, 10, 99);
    cout << "Random Numbers Array  : ";
    for (int i = 0; i < ArrLength; i++)
        cout << NumbersArr[i] << " ";
    cout << "\n";

    clsUtil::ShuffleArray(NumbersArr, ArrLength);
    cout << "Shuffled Numbers Array : ";
    for (int i = 0; i < ArrLength; i++)
        cout << NumbersArr[i] << " ";
    cout << "\n\n";

    // مصفوفة كلمات
    string WordsArr[ArrLength];
    clsUtil::FillArrayWithRandomWords(WordsArr, ArrLength, clsUtil::enCharType::CapitalCharacter, 4);
    cout << "Random Words Array    : ";
    for (int i = 0; i < ArrLength; i++)
        cout << WordsArr[i] << " ";
    cout << "\n\n";

    // مصفوفة مفاتيح (Keys)
    string KeysArr[ArrLength];
    clsUtil::FillArrayWithRandomKeys(KeysArr, ArrLength, clsUtil::enCharType::CapitalCharacter);
    cout << "Random Keys Array     :\n";
    for (int i = 0; i < ArrLength; i++)
        cout << "Key [" << i + 1 << "] : " << KeysArr[i] << "\n";

    return 0;
}