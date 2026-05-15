#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // Step 1: Adjacency list and in-degree tracking
        vector<vector<int>> adj(K);
        vector<int> inDegree(K, 0);

        // Step 2: Compare words to find edges
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].push_back(v);
                    inDegree[v]++;
                    break; // Only the first mismatch matters
                }
            }
        }

        // Step 3: Initialize BFS with 0 in-degree nodes
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        // Step 4: Topological Sort
        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += (char)(node + 'a');

            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string dict1[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << "Alphabet 1: " << sol.findOrder(dict1, 5, 4) << " (Expected: bdac)" << endl;

    // Test Case 2
    string dict2[] = {"caa", "aaa", "aab"};
    cout << "Alphabet 2: " << sol.findOrder(dict2, 3, 3) << " (Expected: cab)" << endl;

    return 0;
}