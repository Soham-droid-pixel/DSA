#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * PROBLEM: Minimum Deletions to Make String Balanced
     * Goal: Remove minimum characters so no 'b' comes before 'a'.
     * Pattern: We want the string to look like "aaa...bbb...".
     * * LOGIC (Greedy / Stack Approach):
     * 1. We iterate through the string.
     * 2. We count 'b's as we see them (`b_count`). These are "potential problems".
     * 3. When we see an 'a':
     * - If we have seen 'b's before it (`b_count > 0`), we have a "ba" conflict.
     * - To fix a "ba" conflict, we must delete one of them.
     * - GREEDY MOVE: We increment `deletions` and decrement `b_count`.
     * (This simulates deleting the 'b' to save the 'a' and make the prefix valid).
     */
    int minimumDeletions(string s) {
        int n = s.length();
        int b_count = 0;
        int deletions = 0;

        for(int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                // Keep track of 'b's found so far. 
                // Any future 'a' will clash with these.
                b_count++;
            } else {
                // We found an 'a'. 
                // If there are 'b's before this 'a', we have a violation ("ba").
                if (b_count > 0) {
                    deletions++; // We remove a character to fix the violation.
                    b_count--;   // We conceptually remove the previous 'b' to pair it with this 'a'.
                }
            }
        }
        return deletions;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;

    // Test Case 1: Mixed
    string s1 = "aababbab";
    cout << "Test Case 1 ('" << s1 << "'): " << sol.minimumDeletions(s1) << endl;
    // Expected: 2 (Delete 'b' at index 2 and 6 -> "aaabbb")

    // Test Case 2: Standard "ba" conflict block
    string s2 = "bbaaaaabb";
    cout << "Test Case 2 ('" << s2 << "'): " << sol.minimumDeletions(s2) << endl;
    // Expected: 2 (Delete the first two 'b's -> "aaaaabb")

    // Test Case 3: Already Balanced
    string s3 = "aabbbb";
    cout << "Test Case 3 ('" << s3 << "'): " << sol.minimumDeletions(s3) << endl;
    // Expected: 0

    // Test Case 4: Your Example
    string s4 = "bbbbbbbbbbbbbb";
    cout << "Test Case 4 ('" << s4 << "'): " << sol.minimumDeletions(s4) << endl;
    // Expected: 0 (No 'a's, so no conflict)

    return 0;
}