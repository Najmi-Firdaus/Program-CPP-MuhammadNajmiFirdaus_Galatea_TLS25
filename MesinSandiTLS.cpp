#include <iostream>
#include <string>
using namespace std;

// balikan string manual
string myReverse(string str)
{
    string result = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        result += str[i];
    }
    return result;
}

// buat sandi dari kata asli
string createPassword(string word)
{
    string withoutVowels = "";
    for (char c : word)
    {
        if (!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
              c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O'))
        {
            withoutVowels += c;
        }
    }

    string reversed = myReverse(withoutVowels);
    int asciiValue = (int)word[0];
    string asciiStr = to_string(asciiValue);

    int mid = reversed.length() / 2;
    string password = reversed.substr(0, mid) + asciiStr + reversed.substr(mid);

    return password;
}

// rekonstruksi kata asli (sebagian)
string reconstructWord(string password)
{
    int pos = 0;
    while (pos < password.length() && isalpha(password[pos]))
        pos++;

    string numStr = "";
    while (pos < password.length() && isdigit(password[pos]))
    {
        numStr += password[pos];
        pos++;
    }

    int asciiValue = stoi(numStr);
    char firstChar = (char)asciiValue;

    string core = password.substr(0, password.length() - numStr.length());
    string reversedCore = myReverse(core);

    string partialWord = firstChar + reversedCore;
    return partialWord;
}

// main program dengan menu
int main()
{
    int pilihan;
    cout << "Mesin Misterius\n";
    cout << "1. Buat sandi dari kata\n";
    cout << "2. Rekonstruksi kata dari sandi\n";
    cout << "Pilih opsi: ";
    cin >> pilihan;

    if (pilihan == 1)
    {
        string word;
        cout << "Masukkan kata asli: ";
        cin >> word;
        cout << "Sandi: " << createPassword(word) << endl;
    }
    else if (pilihan == 2)
    {
        string code;
        cout << "Masukkan sandi: ";
        cin >> code;
        cout << "Rekonstruksi sebagian kata: " << reconstructWord(code) << endl;
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
    return 0;
}
