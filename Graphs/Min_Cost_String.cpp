#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits> // For LLONG_MAX

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Step 1: Initialize a 26x26 grid with "Infinity"
        // This stores the cost to change char 'i' to char 'j'
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));

        // Cost to change a letter to itself is always 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Step 2: Fill in the direct costs given in the input
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a'; // Convert char to index (0-25)
            int v = changed[i] - 'a';
            
            // We take min because there might be multiple ways to do the same change
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 3: Floyd-Warshall Algorithm (The Magic Loop)
        // Checks if going through an intermediate letter 'k' is cheaper
        // e.g., Is 'a -> k -> b' cheaper than 'a -> b'?
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    // If path exists from i->k and k->j, update min cost
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 4: Calculate total cost for the source string
        long long totalCost = 0;
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (u == v) continue; // No change needed

            // If cost is still infinity, it means there's no path -> Impossible
            if (dist[u][v] == LLONG_MAX) return -1;

            totalCost += dist[u][v];
        }

        return totalCost;
    }
};

// --- Driver Code for VS Code ---
int main() {
    Solution sol;

    // Example 1
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed =  {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost =      {2, 5, 5, 1, 2, 20};

    cout << "Output: " << sol.minimumCost(source, target, original, changed, cost) << endl;
    // Expected: 28

    return 0;
}