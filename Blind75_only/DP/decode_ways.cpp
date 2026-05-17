#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // Edge Case: If the message is empty or starts with '0', it's instantly unmappable
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        
        // State variables acting as our lookback markers
        int prev2 = 1; // Represents dp[i-2] -> Empty string base case
        int prev1 = 1; // Represents dp[i-1] -> Substring of length 1 base case
        
        // Start parsing from length 2 up to the total string length n
        for (int i = 2; i <= n; i++) {
            int current = 0;
            
            // Lookback Option 1: Single digit check (s[i-1])
            int singleDigit = s[i - 1] - '0';
            if (singleDigit >= 1 && singleDigit <= 9) {
                current += prev1; // Safely inherits paths from 1 step back
            }
            
            // Lookback Option 2: Double digit check (s[i-2] and s[i-1])
            // Pull out the 2-character substring starting at index (i-2)
            int doubleDigit = stoi(s.substr(i - 2, 2));
            if (doubleDigit >= 10 && doubleDigit <= 26) {
                current += prev2; // Safely inherits paths from 2 steps back
            }
            
            // If both lookbacks fail (e.g., substring "30"), current stays 0, 
            // killing this decoding branch entirely.
            
            // Slide our lookback window forward
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Multiple splits possible
    string s1 = "12";
    cout << "Test Case 1 (\"12\"): " << sol.numDecodings(s1) << " (Expected: 2)" << endl;

    // Test Case 2: Standard branching
    string s2 = "226";
    cout << "Test Case 2 (\"226\"): " << sol.numDecodings(s2) << " (Expected: 3)" << endl;

    // Test Case 3: Invalid leading zero
    string s3 = "06";
    cout << "Test Case 3 (\"06\"): " << sol.numDecodings(s3) << " (Expected: 0)" << endl;

    return 0;
}