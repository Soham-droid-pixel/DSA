#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // Put all dictionary words into a hash set for O(1) rapid lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] represents if the substring s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        
        // Base case: An empty string can always be segmented
        dp[0] = true;
        
        // Outer loop checks every possible prefix length
        for (int i = 1; i <= n; i++) {
            // Inner loop checks every possible split point behind 'i'
            for (int j = 0; j < i; j++) {
                // If the prefix s[0...j-1] is valid AND the remaining chunk is a dictionary word
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Found a valid segmentation for length i, no need to check other splits
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Custom User Example ("takeuforward")
    string s1 = "takeuforward";
    vector<string> wordDict1 = {"take", "forward", "you", "u"};
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test Case 1: " << sol.wordBreak(s1, wordDict1) << " (Expected: true)" << endl;

    // Test Case 2: Custom User Example ("applepineapple")
    string s2 = "applepineapple";
    vector<string> wordDict2 = {"apple"};
    cout << "Test Case 2: " << sol.wordBreak(s2, wordDict2) << " (Expected: false)" << endl;

    // Test Case 3: Standard LeetCode Example
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test Case 3: " << sol.wordBreak(s3, wordDict3) << " (Expected: false)" << endl;

    return 0;
}