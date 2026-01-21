#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Edge case: Empty string has no palindrome
        if (s.empty()) return "";
        
        int start = 0;      // Tracks start index of the longest palindrome found
        int maxLen = 0;     // Tracks length of the longest palindrome found

        // Iterate through every character, treating it as a potential center
        for (int i = 0; i < s.length(); i++) {
            
            // CASE 1: Odd Length Palindromes (Center is strictly at 'i')
            // Example: "aba" -> expands from 'b' (index 1)
            expand(s, i, i, start, maxLen);
            
            // CASE 2: Even Length Palindromes (Center is between 'i' and 'i+1')
            // Example: "abba" -> expands from between 'b' and 'b' (indices 1 and 2)
            expand(s, i, i + 1, start, maxLen);
        }
        
        // Return the substring starting at 'start' with length 'maxLen'
        return s.substr(start, maxLen);
    }

    // Helper Function: Expands outwards from a given center (left, right)
    // We pass 'start' and 'maxLen' by reference (&) so we can update them directly.
    void expand(string& s, int left, int right, int& start, int& maxLen) {
        
        // Loop Condition:
        // 1. left >= 0          -> Don't fall off the start
        // 2. right < s.length() -> Don't fall off the end
        // 3. s[left] == s[right]-> Characters match (Palindrome property)
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            
            // Calculate current palindrome length
            // Formula: right - left + 1
            int currentLen = right - left + 1;
            
            // If this new palindrome is the biggest we've seen, save it!
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left;
            }
            
            // Expand Outwards
            left--;  // Move left pointer to the left
            right++; // Move right pointer to the right
        }
    }
};

// --- Driver Code to Test Your Logic ---
int main() {
    Solution sol;

    // Test Case 1: Odd length result
    string s1 = "babad";
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << sol.longestPalindrome(s1) << endl; 
    // Expected: "bab" or "aba"
    cout << "-----------------" << endl;

    // Test Case 2: Even length result
    string s2 = "cbbd";
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << sol.longestPalindrome(s2) << endl; 
    // Expected: "bb"
    cout << "-----------------" << endl;

    // Test Case 3: Entire string is palindrome
    string s3 = "racecar";
    cout << "Input:  " << s3 << endl;
    cout << "Output: " << sol.longestPalindrome(s3) << endl; 
    // Expected: "racecar"

    return 0;
}