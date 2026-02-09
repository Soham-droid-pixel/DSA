#include <iostream>
#include <vector>
#include <queue>

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
     * PROBLEM: Balance a Binary Search Tree
     * Input: A Binary Search Tree (likely skewed/unbalanced).
     * Output: A Balanced BST with the same values.
     * * STRATEGY:
     * 1. Inorder Traversal: This extracts values from a BST in SORTED order.
     * 2. Build Tree: Use the sorted array to build a new tree.
     * - Pick the MIDDLE element as the root (this guarantees balance).
     * - Recursively do the same for left and right halves.
     */
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedNodes;
        // Step 1: Get sorted values
        inorderTraversal(root, sortedNodes);
        
        // Step 2: Build balanced tree from sorted values
        return buildBalancedTree(sortedNodes, 0, sortedNodes.size() - 1);
    }

private:
    // Helper to get values in sorted order
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }

    // Helper to build tree recursively
    TreeNode* buildBalancedTree(const vector<int>& nodes, int start, int end) {
        if (start > end) return nullptr;

        // Pick the middle element to ensure balance
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);

        // Recursively build left and right subtrees
        node->left = buildBalancedTree(nodes, start, mid - 1);
        node->right = buildBalancedTree(nodes, mid + 1, end);

        return node;
    }
};

// --- Helper: Print Tree (Level Order) to visualize structure ---
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty Tree" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl; // Newline for each level
    }
}

// --- Driver Code ---
int main() {
    Solution sol;

    // Create a Skewed Tree: 1 -> 2 -> 3 -> 4
    // This is essentially a linked list (Very Unbalanced)
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "--- Original Unbalanced Tree (Skewed) ---" << endl;
    printLevelOrder(root);

    // Balance it
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "\n--- Balanced Tree Output ---" << endl;
    printLevelOrder(balancedRoot);

    /*
     * EXPECTED OUTPUT EXPLANATION:
     * Original: 1 -> 2 -> 3 -> 4
     * Sorted Array: [1, 2, 3, 4]
     * Middle of [1,2,3,4] is 2 (index 1).
     * Root becomes 2.
     * Left child of 2 is 1.
     * Right child of 2 is built from [3, 4]. Middle is 3.
     * Structure:
     * 2
     * / \
     * 1   3
     * \
     * 4
     */

    return 0;
}