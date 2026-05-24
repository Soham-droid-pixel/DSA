#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // EDGE CASE 1: If lengths are different, they can never be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create an array of 26 zeroes to track our character inventory
        int count[26] = {0};

        // Single pass: Add for 's', Subtract for 't'
        for (int i = 0; i < s.length(); i++) {
            // Subtracting 'a' from the char converts its ASCII value to a 0-25 index
            // Example: 'a' - 'a' = 0. 'c' - 'a' = 2.
            count[s[i] - 'a']++; 
            count[t[i] - 'a']--; 
        }

        // Verify the inventory balance
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                // If any bucket isn't exactly 0, an imbalance occurred!
                return false; 
            }
        }

        return true; // Perfectly balanced, as all things should be.
    }
};

int main() {
    Solution sol;

    // Test Case 1: Perfect Anagram
    // Input: s = "anagram", t = "nagaram" -> Expected Output: true
    string s1 = "anagram", t1 = "nagaram";
    cout << boolalpha; // Prints 'true' instead of '1'
    cout << "Test Case 1: " << sol.isAnagram(s1, t1) << " (Expected: true)" << endl;

    // Test Case 2: Mismatched Letters
    // Input: s = "rat", t = "car" -> Expected Output: false
    string s2 = "rat", t2 = "car";
    cout << "Test Case 2: " << sol.isAnagram(s2, t2) << " (Expected: false)" << endl;

    // Test Case 3: Different Lengths
    // Input: s = "a", t = "ab" -> Expected Output: false
    string s3 = "a", t3 = "ab";
    cout << "Test Case 3: " << sol.isAnagram(s3, t3) << " (Expected: false)" << endl;

    return 0;
}