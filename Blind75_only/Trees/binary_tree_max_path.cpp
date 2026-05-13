#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSum; // Global variable to track the overall maximum

public:
    int calculateGains(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Base case: null nodes contribute nothing
        }

        // 1. Recursively find the max gain from left and right children.
        // We use max(0, ...) because we ignore any branch that gives a negative sum.
        int leftGain = max(0, calculateGains(node->left));
        int rightGain = max(0, calculateGains(node->right));

        // 2. Calculate the path sum if this node is the 'peak' of the path.
        int currentPathSum = node->val + leftGain + rightGain;

        // 3. Update the global maximum if the current path is better.
        maxSum = max(maxSum, currentPathSum);

        // 4. Return the maximum gain this node can offer to its parent.
        // To continue a path upward, the parent can only pick ONE branch (left or right).
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // Initialize with the smallest possible integer
        calculateGains(root);
        return maxSum;
    }
};

int main() {
    // Example 2: [-10, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl; // Should output 42

    return 0;
}