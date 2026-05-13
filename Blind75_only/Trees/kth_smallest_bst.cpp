#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;
    int ans = 0;

public:
    void traverse(TreeNode* root, int k) {
        if (!root) return;

        traverse(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        traverse(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return ans;
    }
};

int main() {
    // Tree: [3, 1, 4, null, 2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 1;
    cout << "The " << k << "st smallest value is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}