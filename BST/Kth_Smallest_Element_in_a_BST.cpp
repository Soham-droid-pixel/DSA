#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node (usually provided by the platform)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function for Inorder Traversal
    // We pass 'k' by reference so we can decrement it across recursive calls
    void inorder(TreeNode* root, int &k, int &result) {
        if (!root) return;

        // 1. Go Left
        inorder(root->left, k, result);

        // 2. Process Current Node
        k--; // Decrement k for every node we visit
        if (k == 0) {
            result = root->val; // Found the kth element
            return;
        }

        // 3. Go Right (only if we haven't found k yet)
        if (k > 0) {
            inorder(root->right, k, result);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};