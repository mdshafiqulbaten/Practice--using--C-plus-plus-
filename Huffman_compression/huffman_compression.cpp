#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->ch != '#') cout << root->ch << ": " << str << endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    string data = "aaabbc";
    unordered_map<char, int> freq;
    for (char ch : data) freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    printCodes(pq.top(), "");
    return 0;
}
