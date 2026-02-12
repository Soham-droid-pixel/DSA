#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalancedSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        // Iterate through every possible starting position 'i'
        for (int i = 0; i < n; i++) {
            
            // Frequency array to count characters in the current window.
            // Size 26 covers all lowercase English letters ('a' -> 0, 'b' -> 1, etc.)
            // We reset this for every new starting position.
            vector<int> freq(26, 0); 
            
            // Expand the window from 'i' to 'j'
            for (int j = i; j < n; j++) {
                
                // 1. Add the current character s[j] to our count
                freq[s[j] - 'a']++;

                // 2. Validation Logic: 
                // We need to check if ALL present characters have the SAME count.
                bool valid = true;
                int targetCount = 0; // This stores the count we expect all chars to match

                for (int k = 0; k < 26; k++) {
                    // We only care about characters that actually exist in the substring
                    if (freq[k] > 0) {
                        
                        // If this is the first character we've checked, set the standard (targetCount)
                        if (targetCount == 0) {
                            targetCount = freq[k];
                        } 
                        // If we find any character that doesn't match the target, it's invalid.
                        else if (freq[k] != targetCount) {
                            valid = false;
                            break; // Stop checking, this substring is bad
                        }
                    }
                }

                // 3. Update Max Length if the substring is valid
                if (valid) {
                    // Length of substring is (end - start + 1)
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

// --- Main Function for Testing in VS Code ---
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abbac";
    cout << "Input: " << s1 << " | Output: " << sol.longestBalancedSubstring(s1) << " (Expected: 4)" << endl;

    // Test Case 2
    string s2 = "zzabccy";
    cout << "Input: " << s2 << " | Output: " << sol.longestBalancedSubstring(s2) << " (Expected: 4)" << endl;

    // Test Case 3
    string s3 = "aba";
    cout << "Input: " << s3 << " | Output: " << sol.longestBalancedSubstring(s3) << " (Expected: 2)" << endl;

    return 0;
}