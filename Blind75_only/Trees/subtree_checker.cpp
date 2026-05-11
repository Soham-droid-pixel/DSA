#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) && isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    // Main Tree: [3, 4, 5, 1, 2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree: [4, 1, 2]
    TreeNode* sub = new TreeNode(4);
    sub->left = new TreeNode(1);
    sub->right = new TreeNode(2);

    Solution sol;
    if (sol.isSubtree(root, sub)) {
        cout << "Result: True - Subtree found!" << endl;
    } else {
        cout << "Result: False - Not a subtree." << endl;
    }

    return 0;
}