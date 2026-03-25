#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if either string is empty, no window is possible
        if (s.empty() || t.empty()) return "";

        // Frequency map to keep track of characters we "owe" from string t.
        // We use size 128 to cover all standard ASCII characters.
        vector<int> targetCount(128, 0);
        for (char c : t) targetCount[c]++;

        int left = 0, right = 0;
        
        // 'required' acts as our total debt counter. 
        // When required == 0, the current window is "valid".
        int required = t.length(); 
        
        int minLen = INT_MAX;
        int startNode = 0;

        // EXPANSION PHASE: Move the right pointer to find a valid window
        while (right < s.length()) {
            
            // If the character at 'right' is something we still owe (count > 0),
            // we reduce our total debt (required).
            if (targetCount[s[right]] > 0) {
                required--;
            }
            
            // Decrement the ledger for this character.
            // Note: If targetCount becomes negative, it means we have "extra" of that char.
            targetCount[s[right]]--;
            right++;

            // CONTRACTION PHASE: Once the window is valid, try to shrink it
            while (required == 0) {
                
                // 1. Update the minimum window if the current one is smaller
                if (right - left < minLen) {
                    minLen = right - left;
                    startNode = left;
                }

                // 2. Try to "give back" the character at the left pointer
                targetCount[s[left]]++;
                
                // 3. If the character we just gave back was actually needed 
                // (i.e., its count is now positive in the ledger), we owe it again.
                if (targetCount[s[left]] > 0) {
                    required++;
                }
                
                // Move the left pointer to keep shrinking
                left++;
            }
        }

        // If minLen was never updated, it means no valid window was found.
        return (minLen == INT_MAX) ? "" : s.substr(startNode, minLen);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test 1 | Input: s=\"" << s1 << "\", t=\"" << t1 << "\"" << endl;
    cout << "Expected: \"BANC\" | Got: \"" << sol.minWindow(s1, t1) << "\"" << endl << endl;

    // Test Case 2: Entire string is the window
    string s2 = "a", t2 = "a";
    cout << "Test 2 | Input: s=\"" << s2 << "\", t=\"" << t2 << "\"" << endl;
    cout << "Expected: \"a\" | Got: \"" << sol.minWindow(s2, t2) << "\"" << endl << endl;

    // Test Case 3: No valid window (not enough 'a's)
    string s3 = "a", t3 = "aa";
    cout << "Test 3 | Input: s=\"" << s3 << "\", t=\"" << t3 << "\"" << endl;
    cout << "Expected: \"\" | Got: \"" << sol.minWindow(s3, t3) << "\"" << endl;

    return 0;
}