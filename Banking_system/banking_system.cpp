#include <iostream>
using namespace std;

class Account {
    string owner;
    double balance;
public:
    Account(string o, double b) : owner(o), balance(b) {}
    void deposit(double amt) { balance += amt; }
    void withdraw(double amt) { if (amt <= balance) balance -= amt; }
    void display() { cout << owner << "'s Balance: $" << balance << endl; }
};

int main() {
    Account acc("Alice", 1000);
    acc.deposit(250);
    acc.withdraw(100);
    acc.display();
    return 0;
}
