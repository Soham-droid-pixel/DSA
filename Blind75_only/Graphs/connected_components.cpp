#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Standard DFS to mark all nodes in a component as visited
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // 1. Build the Adjacency List
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Undirected graph means edges go both ways
        }

        // 2. Track visited nodes
        vector<bool> visited(n, false);
        int componentCount = 0;

        // 3. Scan all vertices
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // Found a new component!
                componentCount++;
                // Mark all nodes in this component
                dfs(i, adj, visited);
            }
        }

        return componentCount;
    }
};

int main() {
    Solution sol;
    
    // Example: V=5, Edges=[[0,1], [1,2], [3,4]]
    int v = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    
    cout << "Number of Connected Components: " << sol.countComponents(v, edges) << endl;
    // Expected Output: 2 (Component 1: {0,1,2}, Component 2: {3,4})

    return 0;
}