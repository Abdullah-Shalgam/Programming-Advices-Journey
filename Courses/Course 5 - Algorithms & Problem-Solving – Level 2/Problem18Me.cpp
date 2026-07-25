#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string Text;
    cout << "Please enter a Text: ";
    getline(cin, Text);
    return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
    string Encryption = "";
    for (int i = 0; i <= Text.length()-1; i++)
    {
        Encryption += char(Text [i] + EncryptionKey);
    }
    return Encryption;
}

string DecryptText(string Text, short EncryptionKey)
{
    string Decryption = "";
    for (int i = 0; i <= Text.length()-1; i++)
    {
        Decryption += char(Text [i] - EncryptionKey);
    }
    return Decryption;
}

int main()
{
    const short EncryptionKey = 2;
    string Text = ReadText();
    string EncryptedText = EncryptText(Text, EncryptionKey);
    cout << "\nText before encryption\t:   " << Text;
    cout << "\nText after encryption\t:   " << EncryptedText;
    cout << "\nText after decryption\t:   " << DecryptText(EncryptedText, EncryptionKey);
    return 0;
}