#include<iostream>
#include<vector>
using namespace std;

class BinaryTreeNode{
    public:
        int val;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        BinaryTreeNode() {
            left = NULL;
            right = NULL;
        }
}

void FindPath(BinaryTreeNode* root, int target) {
    if (root == NULL) {
        return;
    }
    vector<int> path;
    int current = 0;
    PrintPath(root, target, path, current);
}

void PrintPath(BinaryTreeNode* root, int target, vector<int> path, int current) {
    current += root->val;
    path.push_back(root->val);
    if (current == target && root->left == NULL && root->right == NULL) {
        for (int i = 0; i < path.size(); i ++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    if (root->left != NULL) {
        PrintPath(root->left, target, path, current);
    }
    if (root->right != NULL) {
        PrintPath(root->right, target, path, current);
    }
}
