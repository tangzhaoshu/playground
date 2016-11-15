#include <iostream>;
using namespace std;

class TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode() {
        left = NULL;
        right = NULL
    }
}

TreeNode* FindCmmnAncstr (TreeNode* root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == a || root->val == b) {
        return root;
    }
    TreeNode* left = FindCmmnAncstr(root->left, a, b);
    TreeNode* right = FindCmmnAncstr(root->right, a, b);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return left;
    }
    return right;
}
