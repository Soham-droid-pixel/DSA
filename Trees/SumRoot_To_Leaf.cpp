#include <iostream>

using namespace std;

// Definition for a binary tree node.
// (LeetCode provides this behind the scenes, but you need it to run locally in VS Code)
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
    int sumRootToLeaf(TreeNode* root) {
        // Start the Depth-First Search (DFS) from the root with an initial sum of 0
        return dfs(root, 0);
    }
    
    int dfs(TreeNode *node, int currentSum) {
        // Base case: If we fall off the tree (hit an empty space), return 0 
        // so it doesn't mess up our addition.
        if (node == NULL) {
            return 0;
        }
        
        // The Binary Math Trick:
        // Multiplying by 2 shifts the current binary number to the left by one position.
        // Then we add the current node's value (0 or 1) to the end.
        // Example: If currentSum is 2 (binary 10), and node->val is 1: (2 * 2) + 1 = 5 (binary 101).
        currentSum = (currentSum * 2) + node->val;
        
        // The "Leaf" Check:
        // A node is a leaf if it has absolutely no children (both left and right are NULL).
        // Once we hit a leaf, our binary number is totally finished, so we return it!
        if (node->left == NULL && node->right == NULL) {
            return currentSum;
        }
        
        // If it's not a leaf, we split our path.
        // We tell both the left and right children to keep going down the tree, 
        // and then we add their final totals together.
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};

// --- Main Function for Testing ---
int main() {
    // Let's manually build Example 1: root = [1,0,1,0,1,0,1]
    /*
    
             1
           /   \
          0     1
         / \   / \
        0   1 0   1
    */
    
    // Creating the nodes and linking them together
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    
    // Run the solution
    Solution sol;
    cout << "Total Sum of Root-to-Leaf Numbers: " << sol.sumRootToLeaf(root) << " (Expected: 22)" << endl;
    
    return 0;
}