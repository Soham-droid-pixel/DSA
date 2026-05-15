#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // Helper function to traverse the graph
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // 1. A tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;

        // 2. Build the Adjacency List
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 3. Check for connectivity using DFS
        vector<bool> visited(n, false);
        dfs(0, adj, visited);

        // 4. If all nodes were visited, the graph is connected and thus a valid tree
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Valid Tree
    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {0,3}, {1,4}};
    cout << "Example 1 (Valid): " << (sol.validTree(n1, edges1) ? "True" : "False") << endl;

    // Example 2: Invalid (Cycle)
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
    cout << "Example 2 (Invalid): " << (sol.validTree(n2, edges2) ? "True" : "False") << endl;

    return 0;
}