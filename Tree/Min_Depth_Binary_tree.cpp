#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left == NULL && node->right == NULL)
                return depth;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        depth++;
    }

    return depth;
}

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    cout << "Minimum Depth: " << minDepth(root);

    return 0;
}