#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Task {
    int priority;
    string description;
    bool operator<(const Task& t) const {
        return priority < t.priority; // higher = more urgent
    }
};

int main() {
    priority_queue<Task> pq;
    pq.push({3, "Update firewall"});
    pq.push({1, "Backup system"});
    pq.push({2, "Scan network"});

    while (!pq.empty()) {
        cout << "Task: " << pq.top().description << ", Priority: " << pq.top().priority << endl;
        pq.pop();
    }
    return 0;
}
