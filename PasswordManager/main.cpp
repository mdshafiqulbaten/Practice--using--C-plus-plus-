#include <iostream>
#include "PasswordManager.h"
using namespace std;

int main() {
    PasswordManager pm;
    string master;
    cout << "Enter master password: ";
    cin >> master;

    if (!pm.authenticate(master)) {
        cout << "Access Denied.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n1. Add Password\n2. View Passwords\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                pm.addPassword();
                break;
            case 2:
                pm.viewPasswords();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 3);

    return 0;
}
