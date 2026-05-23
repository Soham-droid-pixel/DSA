#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm> // Required for std::max

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Our dynamic window holding the unique characters currently in our substring
        unordered_set<char> window;
        
        int left = 0;
        int maxLength = 0;

        // The right pointer expands the window one character at a time
        for (int right = 0; right < s.length(); right++) {
            
            // THE CONTRACTION:
            // If the character at 'right' is already in our set, we have a duplicate!
            // We must shrink the window from the 'left' until the duplicate is gone.
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            
            // Now that it's safe, add the current character to the window
            window.insert(s[right]);
            
            // Record the size of the window if it's the biggest we've seen so far
            // Window physical size = right - left + 1
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard repeating string
    // Input: "abcabcbb" -> Expected Output: 3 ("abc", "bca", "cab")
    string s1 = "abcabcbb";
    cout << "Test Case 1 Output: " << sol.lengthOfLongestSubstring(s1) << " (Expected: 3)" << endl;

    // Test Case 2: Single repeating character
    // Input: "bbbbb" -> Expected Output: 1 ("b")
    string s2 = "bbbbb";
    cout << "Test Case 2 Output: " << sol.lengthOfLongestSubstring(s2) << " (Expected: 1)" << endl;

    // Test Case 3: Substring vs Subsequence trap
    // Input: "pwwkew" -> Expected Output: 3 ("wke")
    string s3 = "pwwkew";
    cout << "Test Case 3 Output: " << sol.lengthOfLongestSubstring(s3) << " (Expected: 3)" << endl;

    return 0;
}