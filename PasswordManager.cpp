#include "PasswordManager.h"
#include <iostream>
#include <fstream>

using namespace std;

bool PasswordManager::authenticate(const string& masterPassword) {
    encryptionKey = masterPassword;
    return masterPassword == "admin123"; // 🔐 Change to secure check or hashed key
}

string PasswordManager::xorEncryptDecrypt(const string& text) {
    string result = text;
    for (size_t i = 0; i < text.size(); i++)
        result[i] ^= encryptionKey[i % encryptionKey.size()];
    return result;
}

void PasswordManager::addPassword() {
    string site, username, password;
    cout << "Enter site: ";
    cin >> site;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream out("passwords.txt", ios::app);
    string encrypted = xorEncryptDecrypt(site + " " + username + " " + password);
    out << encrypted << endl;
    out.close();

    cout << "Password saved!\n";
}

void PasswordManager::viewPasswords() {
    ifstream in("passwords.txt");
    string line;
    cout << "\nStored Passwords:\n";
    while (getline(in, line)) {
        cout << xorEncryptDecrypt(line) << endl;
    }
    in.close();
}
