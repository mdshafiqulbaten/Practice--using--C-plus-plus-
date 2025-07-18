#include <iostream>
#include <map>
using namespace std;

class PasswordManager {
    map<string, string> storage;
public:
    void add(const string& site, const string& password) {
        storage[site] = password;
    }
    void get(const string& site) {
        if (storage.count(site))
            cout << "Password for " << site << ": " << storage[site] << endl;
        else
            cout << "No password stored for " << site << endl;
    }
};

int main() {
    PasswordManager pm;
    pm.add("gmail", "Gmail1234!");
    pm.add("github", "Hub9876#");
    pm.get("gmail");
    pm.get("facebook");
    return 0;
}
