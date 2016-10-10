#include <iostream>
#include <string>
using namespace std;

struct Node {
    int val;
    Node *next[26];
    Node() {
        val = 0;
        for (int i = 0; i < 26; i ++) {
            next[i] = NULL;
        }
    }
};

void insert(Node* root, string s) {
    Node* cur = root;
    for (int i = 0; i < (int)s.size(); i ++) {
        if (!cur->next[s[i] - 'a']) {
            Node *next = new Node;
            cur->next[s[i] - 'a'] = next;
        }
        cur = cur->next[s[i] - 'a'];
        cur->val ++;
    }
}

int match(Node* root, string s) {
    Node* cur = root;
    for (int i = 0; i < (int)s.size(); i ++) {
        if (!cur->next[s[i] - 'a']) {
            return 0;
        } else {
            cur = cur->next[s[i] - 'a'];
        }
    }
    return cur->val;
}


int main () {
    int n, m;
    string s;
    cin >> n;
    Node* root = new Node;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        insert(root, s);
    }
    cout << root->val << endl;
    cin >> m;
    for (int i = 0; i < m; i ++) {
        cin >> s;
        cout << match(root, s) << endl;
    }
    return 0;
}
