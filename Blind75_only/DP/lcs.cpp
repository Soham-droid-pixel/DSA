#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Changed return type from 'int' to 'string' to allow returning the actual text
    string longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Step 1: Create and fill the 2D DP matrix for LCS lengths
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Mismatch
                }
            }
        }

        // Step 2: Backtrack from the bottom-right corner to extract the characters
        string lcsStr = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            // If current characters match, they belong to the LCS
            if (text1[i - 1] == text2[j - 1]) {
                lcsStr += text1[i - 1];
                i--; // Move diagonally up-left
                j--;
            }
            // If they don't match, follow the maximum path direction
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--; // Move straight up
            } else {
                j--; // Move straight left
            }
        }

        // Since we tracked from the end, the string is reversed. Flip it back.
        reverse(lcsStr.begin(), lcsStr.end());
        return lcsStr;
    }
};

int main() {
    Solution sol;
    string t1 = "abcde", t2 = "ace";
    cout << "LCS of 'abcde' and 'ace' is: " << sol.longestCommonSubsequence(t1, t2) << endl;
    return 0;
}