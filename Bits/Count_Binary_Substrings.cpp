#include <iostream>
#include <string>
#include <algorithm> // Required for std::min

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        // curr: length of the current block of identical characters
        // prev: length of the previous block of identical characters
        // ans: total count of valid substrings
        int curr = 1, prev = 0, ans = 0;
        
        // Start from the second character (index 1)
        for (int i = 1; i < s.length(); i++) {
            
            // If the current character is the same as the previous one,
            // the current block is continuing to grow.
            if (s[i] == s[i - 1]) {
                curr++;
            } 
            // If the character changes (e.g., from '0' to '1'),
            // the current block ends.
            else {
                // We calculate how many valid substrings we can form 
                // between the 'prev' block and the 'curr' block.
                ans += min(prev, curr);
                
                // The current block now becomes the previous block
                prev = curr;
                // Reset the current block length for the new character
                curr = 1;
            }
        }
        
        // After the loop finishes, we still have the very last pair of blocks 
        // sitting in 'prev' and 'curr' that haven't been added to 'ans' yet.
        ans += min(prev, curr);
        
        return ans;
    }
};

// --- Main Function for Testing ---
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "00110011";
    // Blocks: [2, 2, 2, 2] -> min(0,2)=0(skip first change), min(2,2)=2, min(2,2)=2, min(2,2)=2 -> Total = 6
    cout << "Input: " << s1 << " | Output: " << sol.countBinarySubstrings(s1) << " (Expected: 6)" << endl;
    
    // Test Case 2
    string s2 = "10101";
    // Blocks: [1, 1, 1, 1, 1] -> min(1,1) added 4 times -> Total = 4
    cout << "Input: " << s2 << " | Output: " << sol.countBinarySubstrings(s2) << " (Expected: 4)" << endl;

    return 0;
}