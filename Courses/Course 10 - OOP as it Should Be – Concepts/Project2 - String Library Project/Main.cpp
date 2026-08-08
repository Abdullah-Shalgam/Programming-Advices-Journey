#include <iostream>
#include <vector>
#include "MyStringLib.h" // احفظ الكلاس في هذا الملف

using namespace std;

// دالة مساعدة لطباعة عناوين الأقسام بشكل مرئي مميز
void PrintSectionHeader(const string& Title)
{
    cout << "\n==================================================\n";
    cout << "  " << Title << "\n";
    cout << "==================================================\n";
}

int main()
{
    // ===================================================
    // 1. اختبار المنشئات (Constructors) والمعاملات (Setters & Getters)
    // ===================================================
    PrintSectionHeader("1. CONSTRUCTORS & GETTERS / SETTERS");

    MyStringLib String1; // المنشئ الافتراضي
    cout << "Default Constructor Value: \"" << String1.GetValue() << "\"\n";

    String1.SetValue("Hello World from C++");
    cout << "After SetValue: \"" << String1.GetValue() << "\"\n";

    MyStringLib String2("Parameterized String Test");
    cout << "Parameterized Constructor Value: \"" << String2.GetValue() << "\"\n";


    // ===================================================
    // 2. اختبار تحويلات حالة الأحرف (Case Manipulation)
    // ===================================================
    PrintSectionHeader("2. CASE MANIPULATION (Static & Instance)");

    string TestTextCase = "aBbC dDdE fFgG";
    cout << "Original Text: " << TestTextCase << "\n\n";

    // --- Static Methods ---
    cout << "[Static] LowerAllString:                      " << MyStringLib::LowerAllString(TestTextCase) << endl;
    cout << "[Static] CapitalizeAllString:                 " << MyStringLib::CapitalizeAllString(TestTextCase) << endl;
    cout << "[Static] InvertAllLettersCase:               " << MyStringLib::InvertAllLettersCase(TestTextCase) << endl;
    cout << "[Static] CapitalizeFirstLetterOfEachWord:    " << MyStringLib::CapitalizeFirstLetterOfEachWord(TestTextCase) << endl;
    cout << "[Static] LowerFirstLetterOfEachWord:         " << MyStringLib::LowerFirstLetterOfEachWord(TestTextCase) << endl;

    // --- Instance Methods ---
    MyStringLib ObjCase("aBbC dDdE fFgG");
    cout << "\n--- Instance Methods Modifications ---\n";
    
    ObjCase.CapitalizeAllString();
    cout << "[Instance] CapitalizeAllString:              " << ObjCase.GetValue() << endl;

    ObjCase.LowerAllString();
    cout << "[Instance] LowerAllString:                   " << ObjCase.GetValue() << endl;

    ObjCase.InvertAllLettersCase();
    cout << "[Instance] InvertAllLettersCase:            " << ObjCase.GetValue() << endl;

    ObjCase.CapitalizeFirstLetterOfEachWord();
    cout << "[Instance] CapitalizeFirstLetterOfEachWord: " << ObjCase.GetValue() << endl;

    ObjCase.LowerFirstLetterOfEachWord();
    cout << "[Instance] LowerFirstLetterOfEachWord:      " << ObjCase.GetValue() << endl;


    // ===================================================
    // 3. اختبار الإحصاء والعد (Counting & Analytics)
    // ===================================================
    PrintSectionHeader("3. COUNTING & ANALYTICS");

    string AnalyticsText = "Hello C++ World! 2026. Apple & Banana.";
    cout << "Sample Text: \"" << AnalyticsText << "\"\n\n";

    // Static Testing
    cout << "[Static] CountLength:             " << MyStringLib::CountLength(AnalyticsText) << endl;
    cout << "[Static] CountAllLetters:         " << MyStringLib::CountAllLetters(AnalyticsText) << endl;
    cout << "[Static] CountLowerCaseLetters:   " << MyStringLib::CountLowerCaseLetters(AnalyticsText) << endl;
    cout << "[Static] CountUpperCaseLetters:   " << MyStringLib::CountUpperCaseLetters(AnalyticsText) << endl;
    cout << "[Static] CountVowelLetters:       " << MyStringLib::CountVowelLetters(AnalyticsText) << endl;
    cout << "[Static] CountWords:              " << MyStringLib::CountWords(AnalyticsText) << endl;

    // Specific Character Count (MatchCase = True vs False)
    cout << "[Static] CountSpecificCharacter ('a', MatchCase=true):  " 
         << MyStringLib::CountSpecificCharacter(AnalyticsText, 'a', true) << endl;
    cout << "[Static] CountSpecificCharacter ('a', MatchCase=false): " 
         << MyStringLib::CountSpecificCharacter(AnalyticsText, 'a', false) << endl;

    // Instance Testing
    MyStringLib ObjAnalytics(AnalyticsText);
    cout << "\n[Instance] CountWords:            " << ObjAnalytics.CountWords() << endl;
    cout << "[Instance] CountSpecificCharacter ('l', MatchCase=true): " 
         << ObjAnalytics.CountSpecificCharacter('l', true) << endl;


    // ===================================================
    // 4. اختبار التنسيق والقص (Trimming Spaces)
    // ===================================================
    PrintSectionHeader("4. TRIMMING SPACES");

    string Untrimmed = "    Welcome to Programming!    ";
    cout << "Original Untrimmed: \"" << Untrimmed << "\"\n\n";

    cout << "[Static] TrimLeftSpaces:  \"" << MyStringLib::TrimLeftSpaces(Untrimmed) << "\"\n";
    cout << "[Static] TrimRightSpaces: \"" << MyStringLib::TrimRightSpaces(Untrimmed) << "\"\n";
    cout << "[Static] TrimSpaces:      \"" << MyStringLib::TrimSpaces(Untrimmed) << "\"\n";

    MyStringLib ObjTrim(Untrimmed);
    cout << "[Instance] TrimSpaces:     \"" << ObjTrim.TrimSpaces() << "\"\n";


    // ===================================================
    // 5. اختبار التقسيم والتجميع (Splitting & Joining)
    // ===================================================
    PrintSectionHeader("5. SPLITTING & JOINING");

    string SentenceToSplit = "Saudi-Arabia-Egypt-Jordan-Morocco";
    cout << "String to Split: \"" << SentenceToSplit << "\"\n\n";

    // Testing Split (Static)
    vector<string> vCountries = MyStringLib::SplitString(SentenceToSplit, "-");
    cout << "Tokens after SplitString using delimiter '-':\n";
    for (const string& Country : vCountries)
    {
        cout << " - " << Country << endl;
    }

    // Testing Join (Vector Overload)
    string JoinedFromVector = MyStringLib::JoinStrings(vCountries, " | ");
    cout << "\n[Static] Joined from Vector with ' | ': " << JoinedFromVector << endl;

    // Testing Join (Array Overload)
    string ArrayOfWords[] = { "Object", "Oriented", "Programming", "C++" };
    string JoinedFromArray = MyStringLib::JoinStrings(ArrayOfWords, 4, " -> ");
    cout << "[Static] Joined from Array with ' -> ':  " << JoinedFromArray << endl;

    // Testing Split (Instance)
    MyStringLib ObjSplit("Red,Green,Blue,Yellow");
    vector<string> vColors = ObjSplit.SplitString(",");
    cout << "\n[Instance] Split Colors Count: " << vColors.size() << endl;


    // ===================================================
    // 6. اختبار الاستبدال والعكس والتنظيف (Replacing, Reversing & Cleaning)
    // ===================================================
    PrintSectionHeader("6. REPLACING, REVERSING & PUNCTUATIONS");

    string TextTransform = "I love Java! Java is great, JAVA everywhere.";
    cout << "Original Text: \"" << TextTransform << "\"\n\n";

    // Reverse Words Order
    cout << "[Static] ReverseWordsOrder: \"" << MyStringLib::ReverseWordsOrder(TextTransform) << "\"\n";

    // Replace Word with MatchCase = True vs False
    cout << "[Static] Replace (MatchCase = true)  ['Java' -> 'C++']: \n   -> \"" 
         << MyStringLib::ReplaceWord(TextTransform, "Java", "C++", true) << "\"\n";

    cout << "[Static] Replace (MatchCase = false) ['java' -> 'C++']: \n   -> \"" 
         << MyStringLib::ReplaceWord(TextTransform, "java", "C++", false) << "\"\n";

    // Remove Punctuations
    string PunctuationText = "Hello, World! (This is: C++ String Library; Version 1.0?)";
    cout << "\nText with Punctuations: \"" << PunctuationText << "\"\n";
    cout << "[Static] RemovePunctuationMarks: \"" << MyStringLib::RemovePunctuationMarks(PunctuationText) << "\"\n";

    MyStringLib ObjClean(PunctuationText);
    cout << "[Instance] RemovePunctuationMarks: \"" << ObjClean.RemovePunctuationMarks() << "\"\n";


    // ===================================================
    // 7. اختبار دوال الطباعة (Print Helpers)
    // ===================================================
    PrintSectionHeader("7. PRINT HELPERS");

    string PrintText = "Quick Brown Fox Jumps Over Lazy Dog";
    cout << "Target Text for Printing: \"" << PrintText << "\"\n";

    // Static Helpers
    MyStringLib::PrintFirstLetterOfEachWord(PrintText);
    MyStringLib::PrintAllVowels(PrintText);
    
    cout << "\nPrintEachWord (Static):\n";
    MyStringLib::PrintEachWord("One Two Three");

    // Instance Helpers
    MyStringLib ObjPrint("Alpha Beta Gamma");
    cout << "\nPrintEachWord (Instance):\n";
    ObjPrint.PrintEachWord();

    cout << "\n==================================================\n";
    cout << "         ALL TESTS COMPLETED SUCCESSFULLY!         \n";
    cout << "==================================================\n";

    return 0;
}