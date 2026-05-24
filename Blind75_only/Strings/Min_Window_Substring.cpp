#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // EDGE CASE: If 's' is smaller than 't', it's impossible.
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Use arrays as ultra-fast hash maps for all 128 ASCII characters
        vector<int> targetFreq(128, 0);
        vector<int> windowFreq(128, 0);

        // Populate our "shopping list" with required frequencies
        int requiredUniqueChars = 0; 
        for (char c : t) {
            if (targetFreq[c] == 0) requiredUniqueChars++;
            targetFreq[c]++;
        }

        int left = 0;
        int right = 0;
        int formedUniqueChars = 0; // Tracks how many unique characters have met their quota

        // Trackers for the absolute smallest valid window
        int minLen = -1;
        int minStart = 0;

        // THE SLIDING WINDOW
        while (right < s.length()) {
            char rightChar = s[right];
            windowFreq[rightChar]++;

            // If we just gathered enough of this specific character to meet the quota, tick it off!
            if (targetFreq[rightChar] > 0 && windowFreq[rightChar] == targetFreq[rightChar]) {
                formedUniqueChars++;
            }

            // CONTRACTION PHASE: While our window has everything we need, try to shrink it
            while (left <= right && formedUniqueChars == requiredUniqueChars) {
                
                // 1. Record the current window if it's the smallest we've seen
                int currentWindowLen = right - left + 1;
                if (minLen == -1 || currentWindowLen < minLen) {
                    minLen = currentWindowLen;
                    minStart = left;
                }

                // 2. Shrink the window from the left
                char leftChar = s[left];
                windowFreq[leftChar]--;

                // 3. Did shrinking just ruin our valid window?
                // If we dropped below the required amount for a target character, untick it!
                if (targetFreq[leftChar] > 0 && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formedUniqueChars--;
                }
                
                left++; // Physically move the left pointer forward
            }

            right++; // Expand the right pointer to look for more characters
        }

        // If minLen is still -1, we never found a valid window. Return "".
        return minLen == -1 ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Search
    // Input: s = "ADOBECODEBANC", t = "ABC" -> Expected Output: "BANC"
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test Case 1: " << sol.minWindow(s1, t1) << " (Expected: BANC)" << endl;

    // Test Case 2: Exact Match
    // Input: s = "a", t = "a" -> Expected Output: "a"
    string s2 = "a", t2 = "a";
    cout << "Test Case 2: " << sol.minWindow(s2, t2) << " (Expected: a)" << endl;

    // Test Case 3: Impossible Match (Too many required characters)
    // Input: s = "a", t = "aa" -> Expected Output: ""
    string s3 = "a", t3 = "aa";
    cout << "Test Case 3: " << sol.minWindow(s3, t3) << " (Expected: )" << endl;

    return 0;
}