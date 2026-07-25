#include <iostream>

using namespace std;

char ReadLetter()
{
    char Character;
    cout << "Please enter a Character?:\n";
    cin >> Character;
    return Character;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    char c = ReadLetter();
    cout << endl;
    if (IsVowel(c))
        cout << "YES: Letter '" << c << "' is Vowel.";
    else
        cout << "NO: Letter '"<< c << "' is NOT Vowel.";
    return 0;
}