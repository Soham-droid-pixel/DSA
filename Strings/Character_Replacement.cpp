#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for max()

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency array to store count of 'A' through 'Z'.
        // Size 26 because there are 26 uppercase English letters.
        vector<int> freq(26, 0);
        
        // 'left' pointer for the start of our sliding window.
        int left = 0;
        
        // 'maxFreq' keeps track of the count of the MOST frequent character
        // currently inside our window. This is the character we DO NOT change.
        int maxFreq = 0;
        
        // 'maxLength' stores our final answer (the largest valid window found).
        int maxLength = 0;

        // Loop 'right' from 0 to the end of string.
        // This pointer EXPANDS the window to the right.
        for (int right = 0; right < s.length(); right++) {
            
            // ---------------------------------------------------------
            // STEP 1: ADD (Expand the window)
            // ---------------------------------------------------------
            // Get the integer index (0-25) for the current character.
            // 'A' becomes 0, 'B' becomes 1, etc.
            int charIndex = s[right] - 'A';
            
            // Increment the count for this character.
            freq[charIndex]++;
            
            // Update the count of the majority element in the current window.
            // We want to know: "What is the count of the letter that appears MOST?"
            maxFreq = max(maxFreq, freq[charIndex]);

            // ---------------------------------------------------------
            // STEP 2: CHECK & SHRINK (Make the window valid)
            // ---------------------------------------------------------
            // Formula for validity:
            // (Window Length) - (Count of Majority Char) <= k
            // If the result > k, it means we need too many swaps. It's INVALID.
            
            int currentWindowLength = right - left + 1;
            int replacementsNeeded = currentWindowLength - maxFreq;

            while (replacementsNeeded > k) {
                // If invalid, we must shrink from the left to remove characters.
                
                // 1. Remove the character at 's[left]' from our frequency map
                freq[s[left] - 'A']--;
                
                // 2. Move the left pointer forward
                left++;

                // Recalculate metrics for the while loop condition
                currentWindowLength = right - left + 1;
                // Note: We don't strictly need to reduce maxFreq here because 
                // we are only looking for a LARGER window than before.
                // But conceptually, the replacements count updates because length decreased.
                replacementsNeeded = currentWindowLength - maxFreq;
            }

            // ---------------------------------------------------------
            // STEP 3: UPDATE ANSWER
            // ---------------------------------------------------------
            // If we are here, the window is valid.
            // Check if this window is the biggest one we've seen so far.
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// --- Driver Code to Run the Solution ---
int main() {
    Solution sol;
    
    // Test Case
    string s = "AABABBA";
    int k = 1;

    cout << "Input String: " << s << endl;
    cout << "Max Swaps (k): " << k << endl;
    
    int result = sol.characterReplacement(s, k);
    cout << "Longest Substring Length: " << result << endl;
    // Expected Output: 4

    return 0;
}

/* =============================================================================
   EXAMPLE WALKTHROUGH REVISION
=============================================================================
   Input: s = "AABABBA", k = 1
   Rule: (Window Length - maxFreq) MUST be <= k (1)

   Step | Window String | MaxFreq Char | Changes Needed | Valid? | Action
   -----------------------------------------------------------------------
   1    | [A]           | A:1          | 1-1 = 0        | Yes    | ans = 1
   2    | [A A]         | A:2          | 2-2 = 0        | Yes    | ans = 2
   3    | [A A B]       | A:2          | 3-2 = 1        | Yes    | ans = 3
   4    | [A A B A]     | A:3          | 4-3 = 1        | Yes    | ans = 4
   5    | [A A B A B]   | A:3          | 5-3 = 2        | NO ❌  | Shrink Left
   6    | A [A B A B]   | A:2 (or B:2) | 4-2 = 2        | NO ❌  | Shrink Left
   7    | A A [B A B]   | B:2          | 3-2 = 1        | Yes    | Valid again

   Final Answer: 4
=============================================================================
*/