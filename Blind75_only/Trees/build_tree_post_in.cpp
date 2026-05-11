#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    unordered_map<int, int> mp;
    int postIdx;

public:
    TreeNode* solve(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        // Right then Left for Postorder
        root->right = solve(postorder, mid + 1, inEnd);
        root->left = solve(postorder, inStart, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1;
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;
        return solve(postorder, 0, n - 1);
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Verified Inorder of constructed tree: ";
    printInorder(root); // Should match original inorder array
    cout << endl;

    return 0;
}