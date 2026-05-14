#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node provided in the problem
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Check if clone already exists
        if (copies.count(node)) return copies[node];

        // Create the clone and register it in the map
        Node* copy = new Node(node->val);
        copies[node] = copy;

        // Process neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        return copy;
    }
};

int main() {
    // Manually constructing Example 1: [[2,4],[1,3],[2,4],[1,3]]
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution sol;
    Node* clonedRoot = sol.cloneGraph(n1);

    cout << "Original Root Address: " << n1 << " Val: " << n1->val << endl;
    cout << "Cloned Root Address:   " << clonedRoot << " Val: " << clonedRoot->val << endl;
    
    if (n1 != clonedRoot) {
        cout << "Success: Addresses are different (Deep Copy confirmed)!" << endl;
    }

    return 0;
}