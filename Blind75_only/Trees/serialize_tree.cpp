#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }

private:
    TreeNode* decode(stringstream& ss) {
        string s;
        if (!getline(ss, s, ',')) return nullptr;
        if (s == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = decode(ss);
        root->right = decode(ss);
        return root;
    }
};

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string data = ser.serialize(root);
    cout << "Serialized string: " << data << endl;

    TreeNode* ans = deser.deserialize(data);
    cout << "Deserialized Tree (Preorder): ";
    printPreorder(ans);
    cout << endl;

    return 0;
}