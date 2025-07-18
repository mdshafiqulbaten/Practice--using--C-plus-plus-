#include <iostream>
#include <vector>
using namespace std;

struct Rule {
    string ip;
    string action;
};

class Firewall {
    vector<Rule> rules;
public:
    void addRule(string ip, string action) {
        rules.push_back({ip, action});
    }
    void simulate(string ip) {
        for (auto& rule : rules) {
            if (rule.ip == ip) {
                cout << "IP " << ip << ": " << rule.action << endl;
                return;
            }
        }
        cout << "IP " << ip << ": ALLOW (default)" << endl;
    }
};

int main() {
    Firewall fw;
    fw.addRule("192.168.1.10", "BLOCK");
    fw.addRule("192.168.1.15", "ALLOW");
    fw.simulate("192.168.1.10");
    fw.simulate("192.168.1.20");
    return 0;
}
