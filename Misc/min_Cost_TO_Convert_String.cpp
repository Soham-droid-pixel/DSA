#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

// --- Trie Definition ---
class TrieNode {
public:
    TrieNode* children[26];
    int id;
    
    TrieNode() {
        for(int i=0; i<26; i++) children[i] = nullptr;
        id = -1;
    }
};

class Solution {
    TrieNode* root;
    int idCounter;

    // Helper: Add string to Trie, return unique ID
    int insert(string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        if (curr->id == -1) {
            curr->id = idCounter++;
        }
        return curr->id;
    }

    // Helper: Get ID of a string
    int getId(string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c - 'a']) return -1;
            curr = curr->children[c - 'a'];
        }
        return curr->id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // Reset for fresh run
        root = new TrieNode();
        idCounter = 0;
        
        // 1. Assign IDs to every unique string in 'original' and 'changed'
        for (string& s : original) insert(s);
        for (string& s : changed) insert(s);
        
        int K = idCounter; // Total unique rule strings
        const long long INF = 1e15;
        
        // 2. Build Graph & Run Floyd-Warshall
        // dist[i][j] = cost to convert ID 'i' to ID 'j'
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for(int i=0; i<K; i++) dist[i][i] = 0;
        
        for (int i = 0; i < cost.size(); i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd-Warshall (O(K^3)) - Fast enough since K <= 200
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < K; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < K; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // 3. Dynamic Programming on the 'source' string
        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            
            // Case A: Characters match directly (Cost 0)
            if (source[i] == target[i]) {
                dp[i+1] = min(dp[i+1], dp[i]);
            }
            
            // Case B: Try replacing a substring starting at 'i'
            // We walk down the Trie using 'source' characters.
            // If we find a node with an ID, it means source[i...j] is a valid rule string.
            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int charIdx = source[j] - 'a';
                if (!curr->children[charIdx]) break; // Substring not found in rules
                curr = curr->children[charIdx];
                
                // If curr->id != -1, source[i...j] matches an 'original' string (ID u)
                if (curr->id != -1) {
                    int u = curr->id;
                    
                    // Check if target[i...j] is also a known string (ID v)
                    string subTgt = target.substr(i, j - i + 1);
                    int v = getId(subTgt);
                    
                    if (v != -1 && dist[u][v] != INF) {
                        dp[j+1] = min(dp[j+1], dp[i] + dist[u][v]);
                    }
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    
    string source = "abcd";
    string target = "acbe";
    vector<string> original = {"a","b","c","c","e","d"};
    vector<string> changed =  {"b","c","b","e","b","e"};
    vector<int> cost =        {2, 5, 5, 1, 2, 20};
    
    cout << "Minimum Cost: " << sol.minimumCost(source, target, original, changed, cost) << endl;
    // Expected: 28
    
    return 0;
}