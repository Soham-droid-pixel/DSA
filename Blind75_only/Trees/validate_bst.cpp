#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    // Example 1: Valid BST [2, 1, 3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    // Example 2: Invalid BST [5, 1, 4, null, null, 3, 6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    Solution sol;
    cout << "Test 1 (Valid): " << (sol.isValidBST(root1) ? "True" : "False") << endl;
    cout << "Test 2 (Invalid): " << (sol.isValidBST(root2) ? "True" : "False") << endl;

    return 0;
}