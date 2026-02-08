#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue> // Required for building the tree

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /*
     * PROBLEM: Check if Binary Tree is Height Balanced
     * A tree is balanced if for every node, the height difference 
     * between left and right subtrees is at most 1.
     * * LOGIC (Bottom-Up DFS):
     * Instead of calling height() repeatedly (which is O(N^2)), we return:
     * - The actual height if the subtree is balanced.
     * - -1 if the subtree is UNBALANCED.
     * This allows us to check everything in a single traversal (O(N)).
     */
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

    // Helper function: returns actual height or -1 if unbalanced
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        // Check Left Subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Propagate failure up

        // Check Right Subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Propagate failure up

        // Check current node balance
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Return actual height to parent
        return 1 + max(leftHeight, rightHeight);
    }
};

// --- Helper Code to Build Tree from Vector (BFS) ---
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (nodes[i] != -1) { // -1 represents null
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// --- Driver Code ---
int main() {
    Solution sol;

    // Test Case 1: Balanced Tree [3,9,20,null,null,15,7]
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    vector<int> nodes1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Test Case 1 (Balanced): " << (sol.isBalanced(root1) ? "True" : "False") << endl;
    // Expected: True

    // Test Case 2: Unbalanced Tree [1,2,2,3,3,null,null,4,4]
    //       1
    //      / \
    //     2   2
    //    / \
    //   3   3
    //  / \
    // 4   4
    vector<int> nodes2 = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Test Case 2 (Unbalanced): " << (sol.isBalanced(root2) ? "True" : "False") << endl;
    // Expected: False

    return 0;
}