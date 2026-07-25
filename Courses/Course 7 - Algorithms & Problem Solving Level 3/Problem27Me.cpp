#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadLetter()
{
    char Character;
    cout << "Please enter a Character?:\n";
    cin >> Character;
    return Character;
}

char InvertCharacterCase(char c)
{
    return (islower(c)) ? toupper(c) : tolower(c);
}

int main()
{
    char c = ReadLetter();
    c = InvertCharacterCase(c);
    cout << "\nChar after inverting case:\n";
    cout << c;
    return 0;
}