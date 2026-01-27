#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Required for LLONG_MAX

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Step 1: Build the Graph (Adjacency List)
        // pair<int, int> stores {neighbor_node, weight_cost}
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // A. Add the Normal Edge (u -> v)
            // If we walk the path as intended, it costs 'w'.
            adj[u].push_back({v, w});

            // B. Add the "Switch" Edge (v -> u)
            // The problem says we can "reverse" an incoming edge.
            // If there is an edge u->v, it is incoming to v.
            // If we are at v, we can use the switch to go BACK to u.
            // The cost is 2 * w.
            adj[v].push_back({u, 2 * w});
        }

        // Step 2: Dijkstra's Algorithm Setup
        // We use a Min-Heap Priority Queue to always expand the cheapest path first.
        // Syntax: priority_queue<Type, Container, Comparator>
        // We store {current_total_cost, current_node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Distance array initialized to Infinity (LLONG_MAX)
        // We use 'long long' to prevent overflow during addition
        vector<long long> dist(n, LLONG_MAX);

        // Step 3: Start from Node 0
        dist[0] = 0;
        pq.push({0, 0}); // {cost, node}

        // Step 4: Process the Queue
        while (!pq.empty()) {
            // Extract the node with the smallest cost so far
            long long currentCost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: Lazy Deletion
            // If we found a shorter path to 'u' previously while this old 
            // entry was sitting in the queue, ignore this outdated entry.
            if (currentCost > dist[u]) continue;

            // Optional: If we reached the destination (node n-1), we can stop.
            if (u == n - 1) return currentCost;

            // Explore all neighbors of u
            for (auto& edge : adj[u]) {
                int v = edge.first;       // The neighbor
                int weight = edge.second; // The cost to go there

                // Relaxation Step:
                // If going from Start -> u -> v is cheaper than the 
                // currently known path to v, update it!
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 5: Check result
        // If the distance to the last node is still Infinity, it's unreachable.
        if (dist[n - 1] == LLONG_MAX) {
            return -1;
        }
        return (int)dist[n - 1];
    }
};

// --- Helper Code to Run and Test ---
int main() {
    Solution sol;

    // Test Case 1
    int n1 = 4;
    vector<vector<int>> edges1 = {
        {0, 1, 3},
        {3, 1, 1}, // Logic: We can reverse this to go 1->3 (cost 2*1 = 2)
        {2, 3, 4},
        {0, 2, 2}
    };

    // Path: 0 -> 1 (cost 3) -> 3 (cost 2) = Total 5
    cout << "Test Case 1 Output: " << sol.minCost(n1, edges1) << endl; 
    // Expected: 5

    // Test Case 2
    int n2 = 4;
    vector<vector<int>> edges2 = {
        {0, 2, 1},
        {2, 1, 1},
        {1, 3, 1},
        {2, 3, 3}
    };

    // Path: 0 -> 2 (1) -> 1 (1) -> 3 (1) = Total 3
    cout << "Test Case 2 Output: " << sol.minCost(n2, edges2) << endl;
    // Expected: 3

    return 0;
}