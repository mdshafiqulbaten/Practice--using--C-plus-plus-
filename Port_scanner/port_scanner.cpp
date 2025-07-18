#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

void scan_port(int port) {
    cout << "Scanning port " << port << "... ";
    this_thread::sleep_for(chrono::milliseconds(200));
    if (port % 2 == 0) cout << "Open\n";
    else cout << "Closed\n";
}

int main() {
    vector<thread> threads;
    for (int port = 20; port <= 25; ++port) {
        threads.push_back(thread(scan_port, port));
    }
    for (auto& t : threads) t.join();
    return 0;
}
