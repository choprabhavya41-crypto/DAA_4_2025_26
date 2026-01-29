#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

unordered_map<char, string> huffCode;

void print(Node* root, string str) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffCode[root->ch] = str;
        cout << root->ch << " : " << str << endl;
        return;
    }

    print(root->left, str + "0");
    print(root->right, str + "1");
}

string decode(Node* root, string encoded) {
    string decoded = "";
    Node* curr = root;

    for (char bit : encoded) {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    unordered_map<char, int> freq;
    for (char ch : s)
        freq[ch]++;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (auto it : freq)
        minHeap.push(new Node(it.first, it.second));

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merge = new Node('#', left->freq + right->freq);
        merge->left = left;
        merge->right = right;

        minHeap.push(merge);
    }

    Node* root = minHeap.top();

    cout << "\nHuffman Codes:\n";
    print(root, "");

    string encoded = "";
    cout << "\nEncoded Data:\n";
    for (char ch : s) {
        encoded += huffCode[ch];
    }
    cout << encoded << endl;

    cout << "\nDecoded Data:\n";
    cout << decode(root, encoded) << endl;

    return 0;
}
