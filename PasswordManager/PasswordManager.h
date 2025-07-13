#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>

class PasswordManager {
private:
    std::string encryptionKey;
    std::string xorEncryptDecrypt(const std::string& text);
public:
    bool authenticate(const std::string& masterPassword);
    void addPassword();
    void viewPasswords();
};

#endif
